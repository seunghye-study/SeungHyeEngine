#include "Scene.h"

Game::Scene::Scene()
{
}

Game::Scene::~Scene()
{
}

void Game::Scene::Initialize()
{
}

void Game::Scene::Update()
{
	// Game object update
	for (GameObject* gameObj : mGameObjects)
	{
		gameObj->Update();
	}
}

void Game::Scene::LateUpdate()
{
	for (GameObject* gameObj : mGameObjects)
	{
		gameObj->LateUpdate();
	}
}

void Game::Scene::Render(HDC hdc)
{
	for (GameObject* gameObj : mGameObjects)
	{
		gameObj->Render(hdc);
	}
}

void Game::Scene::AddGameObject(GameObject* gameObject)
{
	mGameObjects.push_back(gameObject);
}