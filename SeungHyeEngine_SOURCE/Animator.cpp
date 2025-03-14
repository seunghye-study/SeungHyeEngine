#include "Animator.h"
#include "Resources.h"
#include "Texture.h"

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


// create animation by folder
void Game::Animator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
{
	Animation* animation = nullptr;
	animation = FindAnimation(name);
	if (animation != nullptr) return;

	int fileCount = 0;
	std::filesystem::path fs(path);
	std::vector<Texture*> images = {};

	for (auto& p : std::filesystem::recursive_directory_iterator(fs))
	{
		std::wstring fileName = p.path().filename();
		std::wstring fullName = p.path();
		Texture* texture = Resources::Load<Texture>(fileName, fullName);
		images.push_back(texture);
		fileCount++;
	}

	UINT sheetWidth = images[0]->GetWidth() * fileCount;
	UINT sheetHeight = images[0]->GetHeight();

	//TODO : 주석해제

	//Texture* spriteSheet = Texture::Create(name, sheetWidth, sheetHeight);

	UINT imageWidth = images[0]->GetWidth();
	UINT imageHeight = images[0]->GetHeight();

	for (size_t i = 0; i < images.size(); i++)
	{
		//BitBlt(spriteSheet->Getdc(), i*imageWidth, 0, imageWidth, imageHeight, images[i]->GetHdc(), 0,0,SRCCOPY);
	}

	//CreateAnimation(name, spriteSheet, Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight), offset, fileCount, duration);
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
