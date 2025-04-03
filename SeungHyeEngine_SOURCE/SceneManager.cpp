#include "SceneManager.h"
#include "DontDestroyOnLoad.h"

using namespace Game;

std::map<std::wstring, Scene*> SceneManager::mScene = {};
Scene* SceneManager::mActiveScene = nullptr;
Scene* SceneManager::mDontDestroyOnLoad = nullptr;

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
	mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
}

void Game::SceneManager::Update()
{
	mActiveScene->Update();
	mDontDestroyOnLoad->Update();
}

void Game::SceneManager::LateUpdate()
{
	mActiveScene->LateUpdate();
	mDontDestroyOnLoad->LateUpdate();
}

void Game::SceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
	mDontDestroyOnLoad->Render(hdc);
}

void Game::SceneManager::Destroy()
{
	mActiveScene->Destroy();
	mDontDestroyOnLoad->Destroy();
}

void Game::SceneManager::Release()
{
	for (auto& iter : mScene)
	{
		delete iter.second;
		iter.second = nullptr;
	}
}