#include "Scene.h"

Game::Scene::Scene() :mLayers{}
{
	CreateLayers();
}

Game::Scene::~Scene()
{

}

void Game::Scene::Initialize()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Initialize();
	}
}

void Game::Scene::Update()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Update();
	}
}

void Game::Scene::LateUpdate()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->LateUpdate();
	}
}

void Game::Scene::Render(HDC hdc)
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Render(hdc);
	}
}

void Game::Scene::Destroy()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Destroy();
	}
}

void Game::Scene::OnEnter()
{

}

void Game::Scene::OnExit()
{

}

void Game::Scene::AddGameObject(GameObject* gameObj, const eLayerType type)
{
	mLayers[(UINT)type]->AddGameObject(gameObj);
}

void Game::Scene::CreateLayers()
{
	mLayers.resize((UINT)eLayerType::Max);
	for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
	{
		mLayers[i] = new Layer();
	}
}

void Game::Scene::EraseGameObject(GameObject* gameObj)
{
	eLayerType layerType = gameObj->GetLayerType();
	mLayers[(UINT)layerType]->EraseGameObject(gameObj);
}