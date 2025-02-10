#include "LoadScene.h"


void Game::LoadTitleScene()
{
	SceneManager::CreateScene<PlayScene>(L"PlayScene");
	SceneManager::LoadScene(L"PlayScene");
}

void Game::LoadPlayScene()
{
	SceneManager::LoadScene(L"PlayScene");
}