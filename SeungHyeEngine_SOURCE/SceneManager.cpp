#include "SceneManager.h"

using namespace Game;

std::map<std::wstring, Scene*> SceneManager::mScene = {};
Scene* SceneManager::mActiveScene = nullptr;

Scene* Game::SceneManager::LoadScene(const std::wstring& name)
{
	if (mActiveScene)
		mActiveScene->OnExit();

	std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);

	if (iter == mScene.end())
		return nullptr;

	mActiveScene = iter->second;
	mActiveScene->OnEnter();

	return iter->second;
}

void Game::SceneManager::Initialize()
{

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
