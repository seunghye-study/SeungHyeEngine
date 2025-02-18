#include "Layer.h"
#include "GameObject.h"


Game::Layer::Layer() : mGameObjects{}
{
}

Game::Layer::~Layer()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		delete gameObj;
		gameObj = nullptr;
	}
}

void Game::Layer::Initialize()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Initialize();
	}
}

void Game::Layer::Update()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Update();
	}
}

void Game::Layer::LateUpdate()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->LateUpdate();
	}
}

void Game::Layer::Render(HDC hdc)
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Render(hdc);
	}
}

void Game::Layer::AddGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
		return;

	mGameObjects.push_back(gameObject);
}
