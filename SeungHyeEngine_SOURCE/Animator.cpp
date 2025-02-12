#include "Animator.h"


Game::Animator::Animator() :
	Component(Game::eComponentType::Animator)
{

}

Game::Animator::~Animator()
{
}

void Game::Animator::Initialize()
{
}

void Game::Animator::Update()
{
	if (mActiveAnimation)
	{
		mActiveAnimation->Update();
		if (mActiveAnimation->IsComplete() == true && mLoop == true)
		{
			mActiveAnimation->Reset();
		}
	}
}

void Game::Animator::LateUpdate()
{
}

void Game::Animator::Render(HDC hdc)
{
	if (mActiveAnimation)
	{
		mActiveAnimation->Render(hdc);
	}
}

void Game::Animator::CreateAnimation(const std::wstring& name, Game::Texture* spriteSheet, Vector2 lestTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
{

}

Game::Animation* Game::Animator::FindAnimation(const std::wstring& name)
{
	return nullptr;
}

void Game::Animator::PlayAnimation(const std::wstring& name, bool loop)
{

}
