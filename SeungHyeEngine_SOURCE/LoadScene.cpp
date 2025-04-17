#include "LoadScene.h"



void Game::LoadTitleScene()
{
	SceneManager::CreateScene<TitleScene>(L"TitleScene");
	SceneManager::LoadScene(L"TitleScene");
}

void Game::LoadPlayScene()
{
	SceneManager::CreateScene<PlayScene>(L"PlayScene");
	SceneManager::LoadScene(L"PlayScene");
}

void Game::LoadToolScene()
{
	SceneManager::CreateScene<ToolScene>(L"ToolScene");
	SceneManager::LoadScene(L"ToolScene");
}

void Game::LoadFarmScene()
{
	SceneManager::CreateScene<FarmScene>(L"FarmScene");
	SceneManager::LoadScene(L"FarmScene");
}

void Game::LoadMineScene()
{
	SceneManager::CreateScene<MineScene>(L"MineScene");
	SceneManager::LoadScene(L"MineScene");
}

void Game::LoadVillageScene()
{
	SceneManager::CreateScene<VillageScene>(L"VillageScene");
	SceneManager::LoadScene(L"VillageScene");
}
