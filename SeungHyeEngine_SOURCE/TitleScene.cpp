#include "TitleScene.h"
#include "Transform.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "GameInput.h"
#include "GamePlayer.h"
#include "LoadScene.h"
#include <SObject.h>
#include <Resources.h>
#include <Texture.h>
#include <Camera.h>
#include <Renderer.h>
#include "GameTime.h"

namespace Game
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		GameObject* camera = Game::Instantiate<GameObject>(eLayerType::BackGround, Vector2(648.0f, 380.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		mainCamera = cameraComp;

		GameObject* bg = Instantiate<GameObject>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(2.0f, 2.0f));
		Texture* bgTexture = Game::Resources::Find<Texture>(L"TilteBackground");
		bgsr->SetTexture(bgTexture);

		GameObject* sBtn = Instantiate<GameObject>(eLayerType::Tile);
		SpriteRenderer* sBtnsr = sBtn->AddComponent<SpriteRenderer>();
		Texture* SbtnTexture = Game::Resources::Find<Texture>(L"StartBtn");
		// TODO : UI 클래스 구현 후 마저
		//Texture* SbtnTexture_MouseHover = Game::Resources::Find<Texture>(L"StartBtn_Hover");
		sBtnsr->SetTexture(SbtnTexture);
		sBtn->GetComponent<Transform>()->SetPosition(Vector2(240.0f, 555.0f));
		sBtn->GetComponent<Transform>()->SetScale(Vector2(2.5f, 2.5f));

		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		

		Scene::LateUpdate();
		Vector2 mousePos = GameInput::GetMousePosition();
		if (GameInput::GetKeyDown(eKeyCode::LButton))
		{
			if (mousePos.x >= 240 && mousePos.x <= 240 + 148 && mousePos.y >= 555 && mousePos.y <= 555 + 185)
			{
				Sleep(1000);
				Game::LoadPlayScene();
			}
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TitleScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void TitleScene::OnExit()
	{
		Scene::OnExit();
	}
}