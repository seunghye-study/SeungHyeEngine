#pragma once

#include "SceneManager.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "../SeungHyeEngine_STATIC/ToolScene.h" 
#include "../SeungHyeEngine_STATIC/FarmScene.h"
#include "../SeungHyeEngine_STATIC/MineScene.h"
#include "../SeungHyeEngine_STATIC/VillageScene.h"

namespace Game
{
	void LoadTitleScene();
	void LoadPlayScene();
	void LoadToolScene();
	void LoadFarmScene();
	void LoadMineScene();
	void LoadVillageScene();
}