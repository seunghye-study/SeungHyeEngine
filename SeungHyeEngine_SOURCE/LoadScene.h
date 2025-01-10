#pragma once

#include "SceneManager.h"
#include "PlayScene.h"

namespace Game
{
	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}