#include "GameObject.h"
#include "GameInput.h"
#include "Transform.h"

void Game::GameObject::Destroy(GameObject* gameObject)
{
	if (gameObject != nullptr)
		gameObject->death();
}

Game::GameObject::GameObject() : mState(eState::Active), mLayerType(eLayerType::None)
{
	mComponents.resize((UINT)eComponentType::End);
	InitializeTransform();
}

Game::GameObject::~GameObject()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr) continue;
		delete comp;
		comp = nullptr;
	}
}

void Game::GameObject::Initialize()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Initialize();
	}
}

void Game::GameObject::Update()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Update();
	}
}

void Game::GameObject::LateUpdate()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;

		comp->LateUpdate();
	}
}

void Game::GameObject::Render(HDC hdc)
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Render(hdc);
	}
}

void Game::GameObject::InitializeTransform()
{
	AddComponent<Transform>();
}

