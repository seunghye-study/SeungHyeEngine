#include "GamePlayer.h"
#include "GameInput.h"

namespace Game
{
	GamePlayer::GamePlayer()
	{

	}

	GamePlayer::~GamePlayer()
	{

	}

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