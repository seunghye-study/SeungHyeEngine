#include "GamePlayer.h"
#include "GameInput.h"
#include "Transform.h"
#include "GameTime.h"

namespace Game
{

	void GamePlayer::Initialize()
	{
		GameObject::Initialize();
	}
	
	void GamePlayer::Update()
	{
		GameObject::Update();
	}

	void GamePlayer::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void GamePlayer::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}