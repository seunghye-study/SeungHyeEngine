#include "Animator.h"


Game::Animator::Animator() :
	Component(Game::eComponentType::Animator)
{

}

Game::Animator::~Animator()
{
	for (auto& iter : mAnimations)
	{
		delete iter.second;
		iter.second = nullptr;
	}
	for (auto& iter : mEvents)
	{
		delete iter.second;
		iter.second = nullptr;
	}
}

void Game::Animator::Initialize()
{
}

void Game::Animator::Update()
{
	if (mActiveAnimation)
	{
		mActiveAnimation->Update();
		Events* events = FindEvents(mActiveAnimation->GetName());

		if (mActiveAnimation->IsComplete() == true)
		{
			if (events)
				events->CompleteEvent();
			if(mLoop)
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
	animation->SetName(name);
	animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);

	animation->SetAnimator(this);

	Events* events = new Events();
	mEvents.insert(std::make_pair(name, events));

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
	if (animation == nullptr) return;

	mActiveAnimation = animation;
	mActiveAnimation->Reset();
	mLoop = loop;
}

Game::Animator::Events* Game::Animator::FindEvents(const std::wstring& name)
{
	auto iter = mEvents.find(name);
	if (iter == mEvents.end()) return nullptr;
	return iter->second;
}

std::function<void()>& Game::Animator::GetStartEvent(const std::wstring& name)
{
	Events* events = FindEvents(name);
	return events->StartEvent.mEvent;
}

std::function<void()>& Game::Animator::GetCompleteEvent(const std::wstring& name)
{
	Events* events = FindEvents(name);
	return events->CompleteEvent.mEvent;
}

std::function<void()>& Game::Animator::GetEndEvent(const std::wstring& name)
{
	Events* events = FindEvents(name);
	return events->EndEvent.mEvent;
}
