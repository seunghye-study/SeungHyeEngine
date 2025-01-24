#include "PlayScene.h"
#include "GameObject.h"
#include "GamePlayer.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace Game
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//background (ground)
		{
			GameObject* ground = new GameObject();
			Transform* tr = ground->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");
			SpriteRenderer* sr = ground->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->SetScale(1, 1);
			sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\Standard_Farm_1.png");
			AddGameObject(ground);
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}