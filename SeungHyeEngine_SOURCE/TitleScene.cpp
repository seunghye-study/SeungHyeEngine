#include "TitleScene.h"
#include "Transform.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "GameInput.h"
#include <GamePlayer.h>

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
		//background
		{
			GameObject* bg = new GameObject();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPosition(Vector2(0, 0));
			tr->SetName(L"TR");
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->SetScale(1, 1);
			sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\Cloudy_Ocean.png");
			AddGameObject(bg, eLayerType::BackGround);
		}
		//title
		{
			GameObject* title = new GameObject();
			Transform* title_tr = title->AddComponent<Transform>();
			title_tr->SetPosition(Vector2(240, 80));
			title_tr->SetName(L"titl                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           e_TR");
			SpriteRenderer* title_sr = title->AddComponent<SpriteRenderer>();
			title_sr->SetName(L"title_sr");
			title_sr->SetScale(2, 2);
			title_sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\TitleButtons.png");
			AddGameObject(title, eLayerType::BackGround);
		}
		// buttons
		{
			GameObject* startBtn = new GameObject();
			Transform* startBtn_tr = startBtn->AddComponent<Transform>();
			startBtn_tr->SetPosition(Vector2(270, 500));
			startBtn_tr->SetName(L"startBtn_tr");
			SpriteRenderer* startBtn_sr = startBtn->AddComponent<SpriteRenderer>();
			startBtn_sr->SetName(L"startBtn_sr");
			startBtn_sr->SetScale(3, 3);
			startBtn_sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\Title_Button_New.bmp");
			AddGameObject(startBtn, eLayerType::BackGround);
		}
		{
			GameObject* loadBtn = new GameObject();
			Transform* loadBtn_tr = loadBtn->AddComponent<Transform>();
			loadBtn_tr->SetPosition(Vector2(530, 500));
			loadBtn_tr->SetName(L"loadBtn_tr");
			SpriteRenderer* loadBtn_sr = loadBtn->AddComponent<SpriteRenderer>();
			loadBtn_sr->SetName(L"loadBtn_tr");
			loadBtn_sr->SetScale(3, 3);
			loadBtn_sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\Title_Button_Load.bmp");
			AddGameObject(loadBtn, eLayerType::BackGround);
		}
		{
			GameObject* ExitBtn = new GameObject();
			Transform* exitBtn_tr = ExitBtn->AddComponent<Transform>();
			exitBtn_tr->SetPosition(Vector2(790, 500));
			exitBtn_tr->SetName(L"exitBtn_tr");
			SpriteRenderer* exitBtn_sr = ExitBtn->AddComponent<SpriteRenderer>();
			exitBtn_sr->SetName(L"exitBtn_sr");
			exitBtn_sr->SetScale(3, 3);
			exitBtn_sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\Title_Button_Exit.bmp");
			AddGameObject(ExitBtn, eLayerType::BackGround);
		}
	}
	void TitleScene::Update()
	{
		if (GameInput::GetKeyDown(EKeyCode::D))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}