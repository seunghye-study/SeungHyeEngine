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

		GameObject::eState state = gameObj->GetState();
		if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
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
		GameObject::eState state = gameObj->GetState();
		if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
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
		GameObject::eState state = gameObj->GetState();
		if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
			continue;
		gameObj->Render(hdc);
	}
}

void Game::Layer::Destroy()
{
	for (GameobjectIter iter = mGameObjects.begin(); iter != mGameObjects.end(); )
	{
		GameObject::eState active = (*iter)->GetState(); 
		if (active == GameObject::eState::Dead)
		{
			GameObject* deadObj = (*iter);
			iter = mGameObjects.erase(iter);

			delete deadObj;
			deadObj = nullptr;

			continue;
		}
		iter++;
	}
}

void Game::Layer::AddGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
		return;

	mGameObjects.push_back(gameObject);
}

void Game::Layer::FindDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
{
	for (GameObject* gameObj : mGameObjects)
	{
		GameObject::eState active = gameObj->GetState();
		if (active == GameObject::eState::Dead)
			gameObjs.push_back(gameObj);
	}
}

void Game::Layer::DeleteGameObjects(std::vector<GameObject*>& deleteObjs)
{
	for (GameObject* obj : deleteObjs)
	{
		delete obj;
		obj = nullptr;
	}
}

void Game::Layer::EraseGameObject()
{
	std::erase_if(mGameObjects, [](GameObject* gameObj)
		{
			return (gameObj)->IsDead();
		});
}