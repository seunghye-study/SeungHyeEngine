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
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"


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
		// MAIN CAMERA
		GameObject* camera = Game::Instantiate<GameObject>(eLayerType::None, Vector2(640.0f, 320.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		mainCamera = cameraComp;

		GameObject* bg = Instantiate<GameObject>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(2.0f, 2.0f));

		Texture* bgTexture = Game::Resources::Find<Texture>(L"Map");
		bgsr->SetTexture(bgTexture);

		mPlayer = Game::Instantiate<GamePlayer>(eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		Texture* playerTexture = Game::Resources::Find<Texture>(L"Farmer");
		
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"PlayerFrontMove", playerTexture, Vector2(0.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.2f);
		animator->PlayAnimation(L"PlayerFrontMove");

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{

		Scene::LateUpdate();
		if (GameInput::GetKeyDown(eKeyCode::N))
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