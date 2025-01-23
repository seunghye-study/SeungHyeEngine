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
		{
			GamePlayer* player = new GamePlayer();
			Transform* tr = player->AddComponent<Transform>();
			tr->SetPos(800, 450);
			tr->SetName(L"TR");
			SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			AddGameObject(player);
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