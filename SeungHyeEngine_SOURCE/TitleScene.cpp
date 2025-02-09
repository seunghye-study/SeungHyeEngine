#include "TitleScene.h"
#include "Transform.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "GameInput.h"
#include <GamePlayer.h>
#include <LoadScene.h>

namespace Game
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		//background
		{

		}
	}
	void TitleScene::Update()
	{
		if (GameInput::GetKeyDown(eKeyCode::D))
		{
			LoadPlayScene();
		}
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}