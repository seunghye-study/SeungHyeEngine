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
		GameObject* camera = Game::Instantiate<GameObject>(eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		mainCamera = cameraComp;

		mPlayer = Game::Instantiate<GamePlayer>(eLayerType::Player);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		Texture* playerTexture = Game::Resources::Find<Texture>(L"Farmer");
		sr->SetTexture(playerTexture);

		GameObject* bg = Instantiate<GameObject>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(3.0f, 3.0f));

		Texture* bgTexture = Game::Resources::Find<Texture>(L"Map");
		bgsr->SetTexture(bgTexture);

		Scene::Initialize();
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

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{

	}
}