#include "SceneManager.h"

using namespace Game;

// init
std::map<std::wstring, Scene*> SceneManager::mScene = {};
Scene* SceneManager::mActiveScene = nullptr;

void Game::SceneManager::Initialize()
{
	mActiveScene->Initialize();
}

void Game::SceneManager::Update()
{
	mActiveScene->Update();
}

void Game::SceneManager::LateUpdate()
{
	mActiveScene->LateUpdate();
}

void Game::SceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
}
