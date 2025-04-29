#include "UIManager.h"

namespace Game
{
	std::unordered_map<eUIType, UIBase*> mUIs = {};
	std::stack<UIBase*> mUIBases = {};
	std::queue<eUIType> mRequestUiQueue = {};
	UIBase* mActiveUI = nullptr; 
}

void Game::UIManager::Initalize()
{
}

void Game::UIManager::OnLoad(eUIType type)
{
	std::unordered_map<eUIType, UIBase*>::iterator iter = mUIs.find(type);
	if (iter == mUIs.end()) // ¾øÀ¸¸é
	{
		OnFail();
		return;
	}
	OnComplete(iter->second); // ui base
}

void Game::UIManager::Update()
{
	std::stack<UIBase*> uiBases = Game::mUIBases;
	while (!uiBases.empty())
	{
		UIBase* uiBase = mUIBases.top();
		if (uiBase)
		{
			uiBase->Update();
			uiBases.pop();
		}
	}
	if (mRequestUiQueue.size() > 0)
	{
		eUIType requestUI = mRequestUiQueue.front();
		mRequestUiQueue.pop();
		OnLoad(requestUI);
	}
}

void Game::UIManager::LateUpdate()
{
	std::stack<UIBase*> uiBases = mUIBases;
	while (!uiBases.empty())
	{
		UIBase* uiBase = uiBases.top();
		if (uiBase)
		{
			uiBase->LateUpdate();
			uiBases.pop();
		}
	}
}

void Game::UIManager::Render(HDC hdc)
{
	std::stack<UIBase*> uiBases = mUIBases;
	while (!uiBases.empty())
	{
		UIBase* uiBase = uiBases.top();
		if (uiBase)
		{
			uiBase->Render(hdc);
			uiBases.pop();
		}
	}
}

void Game::UIManager::OnComplete(UIBase* addUI)
{
	if (addUI == nullptr)
		return;

	addUI->Initialize();
	addUI->Active();
	addUI->Update();

	if (addUI->IsFullScreen())
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			uiBases.pop();
			if (uiBase)
			{
				uiBase->InActive();
			}
		}
	}

	mUIBases.push(addUI);
	mActiveUI = nullptr;
}

void Game::UIManager::OnFail()
{
	mActiveUI = nullptr;
}

void Game::UIManager::Release()
{
	for (auto iter : mUIs)
	{
		delete iter.second;
		iter.second = nullptr;
	}
}

void Game::UIManager::Push(eUIType type)
{
	mRequestUiQueue.push(type);
}

void Game::UIManager::Pop(eUIType type)
{
	if (mUIBases.size() <= 0)
		return;

	UIBase* uibase = nullptr;
	while (mUIBases.size() > 0)
	{
		uibase = mUIBases.top();
		mUIBases.pop();
	}
}
