#include "PlayScene.h"
#include "GameObject.h"
#include "GamePlayer.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameInput.h"
#include "Object.h"

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
		mPlayer = Game::Instantiate<GameObject>(eLayerType::BackGround, Vector2(0.0f, 0.0f));
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\Standard_Farm_1.png");
		//Scene::Initialize();
		//background (ground)
		//{
		//	GameObject* ground = new GameObject();
		//	Transform* tr = ground->AddComponent<Transform>();
		//	tr->SetPosition(Vector2(0, 0));
		//	tr->SetName(L"TR");
		//	SpriteRenderer* sr = ground->AddComponent<SpriteRenderer>();
		//	sr->SetName(L"SR");
		//	sr->SetScale(1, 1);
		//	sr->ImageLoad(L"C:\\win32API\\SeungHyeEngine\\Resources\\Standard_Farm_1.png");
		//	AddGameObject(ground, eLayerType::BackGround);
		//}
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