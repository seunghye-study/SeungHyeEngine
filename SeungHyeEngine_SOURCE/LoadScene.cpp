#include "LoadScene.h"


void Game::LoadTitleScene()
{
	SceneManager::CreateScene<TitleScene>(L"TitleScene");
	SceneManager::CreateScene<PlayScene>(L"PlayScene");
	SceneManager::LoadScene(L"TitleScene");
}

void Game::LoadPlayScene()
{
	SceneManager::LoadScene(L"PlayScene");
}