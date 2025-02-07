#include "TitleScene.h"
#include "Transform.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "GameInput.h"
#include <GamePlayer.h>
#include <LoadScene.h>

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
	}
	void TitleScene::Update()
	{
		if (GameInput::GetKeyDown(eKeyCode::D))
		{
			LoadPlayScene();
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