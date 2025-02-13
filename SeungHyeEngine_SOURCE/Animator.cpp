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

void Game::Animator::CreateAnimation(const std::wstring& name, Game::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
{
	Animation* animation = nullptr;
	animation = FindAnimation(name);
	if (animation != nullptr) return;

	animation = new Animation();
	animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);

	animation->SetAnimator(this);
	mAnimations.insert(std::make_pair(name, animation));
}

Game::Animation* Game::Animator::FindAnimation(const std::wstring& name)
{
	auto iter = mAnimations.find(name);
	if (iter == mAnimations.end())
		return nullptr;
	return iter->second;
}

void Game::Animator::PlayAnimation(const std::wstring& name, bool loop)
{
	Animation* animation = FindAnimation(name);
	if (animation != nullptr) return;

	mActiveAnimation = animation;
	mActiveAnimation->Reset();
	mLoop = loop;
}
