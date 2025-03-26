#include "PlayScene.h"
#include "GameObject.h"
#include "GamePlayer.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameInput.h"
#include "SObject.h"
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"
#include "..\\SeungHyeEngine_STATIC\Cat.h"
#include "..\\SeungHyeEngine_STATIC\CatScript.h"
#include "CollisionManager.h"


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
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);

		GameObject* camera = Game::Instantiate<GameObject>(eLayerType::None, Vector2(1030.0f*3, 230.0f*3));
		Camera* cameraComp = camera->AddComponent<Camera>();
		mainCamera = cameraComp;

		GameObject* bg = Instantiate<GameObject>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(7.0f, 7.0f));

		Texture* bgTexture = Game::Resources::Find<Texture>(L"FarmHouse");
		bgsr->SetTexture(bgTexture);

		mPlayer = Game::Instantiate<GamePlayer>(eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		
		Texture* IdleTexture = Game::Resources::Find<Texture>(L"Idle");
		Texture* t_GoLeft  = Game::Resources::Find<Texture>(L"GoLeft");
		Texture* t_GoRight = Game::Resources::Find<Texture>(L"GoRight");
		Texture* t_GoUp = Game::Resources::Find<Texture>(L"GoUp");
		Texture* t_GoDown = Game::Resources::Find<Texture>(L"GoDown");
		Texture* GiveWaterFront = Game::Resources::Find<Texture>(L"GiveWaterFront");

		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"Idle", IdleTexture, Vector2(500.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 1, 0.1f);
		animator->CreateAnimation(L"GoLeft", t_GoLeft, Vector2(1500.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"GoRight", t_GoRight, Vector2(0.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"GoUp", t_GoUp, Vector2(0.0f, 250.0f), Vector2(250, 250), Vector2::Zero, 8, 0.1f);
		animator->CreateAnimation(L"GoDown", t_GoDown, Vector2(0.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"GiveWaterFront", GiveWaterFront, Vector2(0.0f, 2000.0f), Vector2(250, 250), Vector2::Zero, 12, 0.1f);
		animator->PlayAnimation(L"Idle", false);
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(1030.0f*3, 230.0f*3));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));

		{
			Cat* cat = Game::Instantiate<Cat>(eLayerType::Animal);
			cat->AddComponent<CatScript>();
			Texture* catTex = Resources::Find<Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();
			catAnimator->CreateAnimation(L"DownWalk", catTex
				, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", catTex
				, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", catTex
				, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", catTex
				, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", catTex
				, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"Grooming", catTex
				, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LayDown", catTex
				, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			catAnimator->PlayAnimation(L"SitDown", false);
			cat->GetComponent<Transform>()->SetPosition(Vector2(1030.0f * 3, 230.0f * 3));
			cat->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));
		}
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