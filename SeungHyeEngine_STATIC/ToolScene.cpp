#include "ToolScene.h"
#include "Camera.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "Resources.h"
#include "Texture.h"
#include "SObject.h"
#include "Renderer.h"
#include "GameInput.h"

Game::ToolScene::ToolScene()
{
}

Game::ToolScene::~ToolScene()
{
}

void Game::ToolScene::Initialize()
{
	GameObject* camera = Instantiate<GameObject>(eLayerType::Player, Vector2(344.0f, 422.0f));
	Camera* cameraComp = camera->AddComponent<Camera>();
	mainCamera = cameraComp;

	Tile* tile = Instantiate<Tile>(eLayerType::Tile);
	TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
	tmr->SetTexture(Resources::Find<Texture>(L"FarmSheet"));

	Scene::Initialize();
}

void Game::ToolScene::Update()
{
	Scene::Update();
}

void Game::ToolScene::LateUpdate()
{
	Scene::LateUpdate();

	if (GameInput::GetKeyDown(eKeyCode::LButton))
	{
		if (TilemapRenderer::SelectedIndex.x < 0 || TilemapRenderer::SelectedIndex.y < 0)
			return;

		Vector2 pos = GameInput::GetMousePosition();
		int idxX = pos.x/TilemapRenderer::TileSize.x;
		int idxY = pos.y/TilemapRenderer::TileSize.y;

		Tile* tile = Instantiate<Tile>(eLayerType::Tile);
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
		tmr->SetTexture(Resources::Find<Texture>(L"FarmSheet"));

		// 클릭한 타일
		tmr->SetIndex(TilemapRenderer::SelectedIndex);

		// 월드 내 타일 위치 설정
		tile->SetPosition(idxX, idxY);
	}
	if (GameInput::GetKeyDown(eKeyCode::S))
	{
		//Save();
	}
	if (GameInput::GetKeyDown(eKeyCode::L))
	{
		//Load();
	}
}

void Game::ToolScene::Render(HDC hdc)
{
	Scene::Render(hdc);
	for (size_t i = 0; i < 50; i++)
	{
		MoveToEx(hdc, TilemapRenderer::TileSize.x * i, 0, NULL);
		LineTo(hdc, TilemapRenderer::TileSize.x * i, 1000);
	}

	for (size_t i = 0; i < 50; i++)
	{
		MoveToEx(hdc, 0, TilemapRenderer::TileSize.y * i, NULL);
		LineTo(hdc, 1000, TilemapRenderer::TileSize.y * i);
	}

	// 선택 하이라이트
	if (TilemapRenderer::SelectedIndex.x >= 0 && TilemapRenderer::SelectedIndex.y >= 0)
	{
		HPEN redPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

		RECT selectRect = {
			(int)(TilemapRenderer::SelectedIndex.x * TilemapRenderer::OriginTileSize.x),
			(int)(TilemapRenderer::SelectedIndex.y * TilemapRenderer::OriginTileSize.y),
			(int)((TilemapRenderer::SelectedIndex.x + 1) * TilemapRenderer::OriginTileSize.x),
			(int)((TilemapRenderer::SelectedIndex.y + 1) * TilemapRenderer::OriginTileSize.y)
		};

		Rectangle(hdc, selectRect.left, selectRect.top, selectRect.right, selectRect.bottom);

		SelectObject(hdc, oldPen);
		SelectObject(hdc, oldBrush);
		DeleteObject(redPen);
	}
	
	//디버깅용 출력
	/*Vector2 selected = TilemapRenderer::SelectedIndex;
	wchar_t debugText[100] = {};
	swprintf_s(debugText, 100, L"선택된 인덱스: (%d, %d)", (int)selected.x, (int)selected.y);
	TextOut(hdc, 10, 10, debugText, wcslen(debugText));*/
}

void Game::ToolScene::OnEnter()
{
	Scene::OnEnter();
}

void Game::ToolScene::OnExit()
{
	Scene::OnExit();
}

LRESULT Game::ToolScene::TileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		int idxX = mousePos.x / TilemapRenderer::OriginTileSize.x;
		int idxY = mousePos.y / TilemapRenderer::OriginTileSize.y;

		TilemapRenderer::SelectedIndex = Vector2(idxX, idxY);
		OutputDebugString(L"[TileProc] Selected Tile Index Set.\n");
	}
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		Game::Texture* texture = Resources::Find<Texture>(L"FarmSheet");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
