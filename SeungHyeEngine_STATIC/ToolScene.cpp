#include "ToolScene.h"
#include "Camera.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "Resources.h"
#include "Texture.h"
#include "SObject.h"
#include "Renderer.h"
#include "GameInput.h"
#include "CameraScript.h"

Game::ToolScene::ToolScene()
{
}

Game::ToolScene::~ToolScene()
{
}

void Game::ToolScene::Initialize()
{
	GameObject* camera = Instantiate<GameObject>(eLayerType::Player, Vector2(0.0f, 0.0f));
	Camera* cameraComp = camera->AddComponent<Camera>();
	camera->AddComponent<CameraScript>();
	mainCamera = cameraComp;

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
		Vector2 pos = GameInput::GetMousePosition();
		pos = mainCamera->CalculateTilePosition(pos);
		int idxX = pos.x / TilemapRenderer::TileSize.x;
		int idxY = pos.y / TilemapRenderer::TileSize.y;

		Tile* tile = Instantiate<Tile>(eLayerType::Tile);
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
		tmr->SetTexture(Resources::Find<Texture>(L"FarmSheet"));
		tmr->SetIndex(TilemapRenderer::SelectedIndex);
		
		tile->SetIndexPosition(idxX, idxY);
		mTiles.push_back(tile);
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
		Vector2 pos = mainCamera->CalculatePosition
		(
			Vector2(TilemapRenderer::TileSize.x * i, 0.0f)
		);

		MoveToEx(hdc, pos.x, 0, NULL);
		LineTo(hdc, pos.x, 1000);
	}

	for (size_t i = 0; i < 50; i++)
	{
		Vector2 pos = mainCamera->CalculatePosition
		(
			Vector2(0.0f, TilemapRenderer::TileSize.y * i)
		);

		MoveToEx(hdc, 0, pos.y, NULL);
		LineTo(hdc, 1000, pos.y);
	}
}

void Game::ToolScene::OnEnter()
{
	Scene::OnEnter();
}

void Game::ToolScene::OnExit()
{
	Scene::OnExit();
}

void Game::ToolScene::RenderGreed(HDC hdc)
{

}

void Game::ToolScene::CreateTileObject()
{

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
