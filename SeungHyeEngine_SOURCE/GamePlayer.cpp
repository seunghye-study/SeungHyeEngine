#include "GamePlayer.h"
#include "GameInput.h"

namespace Game
{
	GamePlayer::GamePlayer() :
		mX(0.0f)
		, mY(0.0f)
	{

	}

	GamePlayer::~GamePlayer()
	{

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