#pragma once

#include "SceneManager.h"
#include "TitleScene.h"

namespace Game
{
	void LoadTitleScene()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::LoadScene(L"TitleScene");
	}
}