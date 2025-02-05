#pragma once

#include "SceneManager.h"
#include "TitleScene.h"
#include "PlayScene.h"

namespace Game
{
	void LoadTitleScene()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"TitleScene");
	}
	void LoadPlayScene()
	{
		SceneManager::LoadScene(L"PlayScene");
	}
}