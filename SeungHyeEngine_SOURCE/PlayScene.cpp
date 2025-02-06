#include "PlayScene.h"
#include "GameObject.h"
#include "GamePlayer.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameInput.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"

namespace Game
{
	PlayScene::PlayScene() : mPlayer()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//게임오브젝트 만들기전에 리소스들 전부 Load해두면 좋다.
		mPlayer = Game::Instantiate<GameObject>(eLayerType::BackGround, Vector2(100.0f, 100.0f));

		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();

		Texture* bg = Resources::Find<Texture>(L"BG");
		sr->SetTexture(bg);

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (GameInput::GetKeyDown(EKeyCode::A))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{

	}
}