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

		if (gameObj->IsActive() == false)
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

		if (gameObj->IsActive() == false)
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
		if (gameObj->IsActive() == false)
			continue;

		gameObj->Render(hdc);
	}
}

void Game::Layer::Destroy()
{
	std::vector<GameObject*> deleteObjects = {};

	findDeadGameObjects(deleteObjects);
	eraseGameObject();
	deleteGameObjects(deleteObjects);
}


void Game::Layer::AddGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
		return;

	mGameObjects.push_back(gameObject);
}

void Game::Layer::EraseGameObject(GameObject* gameObject)
{
	std::erase_if(mGameObjects, [=](GameObject* gameObj) {
		return gameObj == gameObject;
		});
}

void Game::Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
{
	for (GameObject* gameObj : mGameObjects)
	{
		GameObject::eState active = gameObj->GetState();
		if (active == GameObject::eState::Dead)
		{
			gameObjs.push_back(gameObj);
		}
	}
}

void Game::Layer::deleteGameObjects(std::vector<GameObject*> gameObjs)
{
	for (GameObject* obj : gameObjs)
	{
		delete obj;
		obj = nullptr;
	}
}

void Game::Layer::eraseGameObject()
{
	std::erase_if(mGameObjects, [](GameObject* gameObj) {
		return (gameObj)->IsDead();
		});
}