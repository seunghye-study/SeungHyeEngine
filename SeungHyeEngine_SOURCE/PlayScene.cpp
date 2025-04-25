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
#include "BoxCollider2D.h"
#include "RigidBody.h"
#include <LoadScene.h>


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
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::BackGround, true);

		GameObject* camera = Game::Instantiate<GameObject>(eLayerType::Player, Vector2(0.0f, 0.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		mainCamera = cameraComp;
		
		GameObject* bg = Instantiate<GameObject>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		Texture* bgTexture = Game::Resources::Find<Texture>(L"FarmHouse");
		bgsr->SetTexture(bgTexture);
		bgsr->SetSize(Vector2(1.5f, 1.5f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(-260.0f, -320.0f));

		mPlayer = Game::Instantiate<GamePlayer>(eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		BoxCollider2D* playerCollider = mPlayer->AddComponent<BoxCollider2D>();
		playerCollider->SetOffset({ 90.0f, 65.0f });
		playerCollider->SetSize({ 0.7f, 1.2f });
		
		Texture* IdleTexture = Game::Resources::Find<Texture>(L"Idle");
		Texture* IdleTexture_left = Game::Resources::Find<Texture>(L"LeftIdle");
		Texture* IdleTexture_right = Game::Resources::Find<Texture>(L"RightIdle");
		Texture* IdleTexture_up = Game::Resources::Find<Texture>(L"UpIdle");
		Texture* t_GoLeft  = Game::Resources::Find<Texture>(L"GoLeft");
		Texture* t_GoRight = Game::Resources::Find<Texture>(L"GoRight");
		Texture* t_GoUp = Game::Resources::Find<Texture>(L"GoUp");
		Texture* t_GoDown = Game::Resources::Find<Texture>(L"GoDown");
		Texture* GiveWaterFront = Game::Resources::Find<Texture>(L"GiveWaterFront");
		Texture* GiveWaterLeft = Game::Resources::Find<Texture>(L"GiveWaterFront");
		Texture* GiveWaterRight = Game::Resources::Find<Texture>(L"GiveWaterFront");
		Texture* GiveWaterUp = Game::Resources::Find<Texture>(L"GiveWaterFront");

		Animator* animator = mPlayer->AddComponent<Animator>();
		Vector2 offset = { 0.0f, 0.0f };
		animator->CreateAnimation(L"Idle", IdleTexture, Vector2(500.0f, 0.0f), Vector2(250, 250), offset, 1, 0.1f);
		animator->CreateAnimation(L"LeftIdle", IdleTexture_left, Vector2(1500.0f, 0.0f), Vector2(250, 250), offset, 1, 0.1f);
		animator->CreateAnimation(L"RightIdle", IdleTexture_right, Vector2(750.0f, 0.0f), Vector2(250, 250), offset, 1, 0.1f);
		animator->CreateAnimation(L"UpIdle", IdleTexture_up, Vector2(0.0f, 250.0f), Vector2(250, 250), offset, 1, 0.1f);
		animator->CreateAnimation(L"GoLeft", t_GoLeft, Vector2(1500.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"GoRight", t_GoRight, Vector2(0.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"GoUp", t_GoUp, Vector2(0.0f, 250.0f), Vector2(250, 250), Vector2::Zero, 8, 0.1f);
		animator->CreateAnimation(L"GoDown", t_GoDown, Vector2(0.0f, 0.0f), Vector2(250, 250), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"GiveWaterFront", GiveWaterFront, Vector2(0.0f, 2000.0f), Vector2(250, 250), Vector2::Zero, 12, 0.1f);
		animator->CreateAnimation(L"GiveWaterLeft", GiveWaterLeft, Vector2(0.0f, 2250.0f), Vector2(250, 250), Vector2::Zero, 5, 0.2f);
		animator->CreateAnimation(L"GiveWaterRight", GiveWaterRight, Vector2(1500.0f, 1750.0f), Vector2(250, 250), Vector2::Zero, 5, 0.2f);
		animator->CreateAnimation(L"GiveWaterUp", GiveWaterUp, Vector2(1250.0f, 2250.0f), Vector2(250, 250), Vector2::Zero, 3, 0.4f);
		
		animator->PlayAnimation(L"Idle", false);
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(-125.0f, -125.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		mPlayer->AddComponent<RigidBody>();

		//Background Collider
		{
			GameObject* UpWall = Game::Instantiate<GameObject>(eLayerType::BackGround);
			BoxCollider2D* collider = UpWall->AddComponent<BoxCollider2D>();
			collider->SetSize(Vector2(5.0f, 1.0f));
			collider->SetOffset(Vector2(0.0f, 0.0f));
			UpWall->GetComponent<Transform>()->SetPosition(Vector2(-248.0f,-320.0f));
		}

		/*{
			Cat* cat = Game::Instantiate<Cat>(eLayerType::Animal);
			cat->AddComponent<CatScript>();
			CircleCollider* catCollider = cat->AddComponent<CircleCollider>();
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
			cat->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 300.0f));
			cat->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));
		}*/

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		if (GameInput::GetKeyDown(eKeyCode::SpaceBar))
		{
			LoadTitleScene();
		}
		if (GameInput::GetKeyDown(eKeyCode::N))
		{
			LoadFarmScene();
		}
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		GameMath::Vector2 playerPos = mPlayer->GetComponent<Transform>()->GetPosition();
		wchar_t str[100] = {};
		swprintf_s(str, 100, L"Player Position: (%.0f, %.0f)", playerPos.x, playerPos.y);

		TextOut(hdc, 10, 30, str, wcslen(str));
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{
		Scene::OnExit();
	}
}