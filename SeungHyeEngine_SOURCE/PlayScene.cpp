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
		GameObject* camera = Game::Instantiate<GameObject>(eLayerType::None, Vector2(600.0f, 500.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		mainCamera = cameraComp;

		GameObject* bg = Instantiate<GameObject>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(1.5f, 1.5f));

		Texture* bgTexture = Game::Resources::Find<Texture>(L"FarmHouse");
		bgsr->SetTexture(bgTexture);

		mPlayer = Game::Instantiate<GamePlayer>(eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		Texture* IdleTexture = Game::Resources::Find<Texture>(L"Idle");
		Texture* t_GoLeft  = Game::Resources::Find<Texture>(L"GoLeft");
		Texture* t_GoRight = Game::Resources::Find<Texture>(L"GoRight");
		Texture* t_GoUp = Game::Resources::Find<Texture>(L"GoUp");
		Texture* t_GoDown = Game::Resources::Find<Texture>(L"GoDown");

		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"Idle", IdleTexture, Vector2(500.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 1, 0.2f);
		animator->CreateAnimation(L"GoLeft", t_GoLeft, Vector2(1500.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.2f);
		animator->CreateAnimation(L"GoRight", t_GoRight, Vector2(0.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.2f);
		animator->CreateAnimation(L"GoUp", t_GoUp, Vector2(0.0f, 250.0f), Vector2(250, 250), Vector2::Zero, 8, 0.2f);
		animator->CreateAnimation(L"GoDown", t_GoDown, Vector2(0.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.2f);
		animator->PlayAnimation(L"Idle");
		
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