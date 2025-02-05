#include <iostream>
#include "GameObject.h"
#include "GameInput.h"
#include "Transform.h"

Game::GameObject::GameObject()
{
	InitializeTransform();
}

Game::GameObject::~GameObject()
{
	for (Component* comp : mComponents)
	{
		delete comp;
		comp = nullptr;
	}
}

void Game::GameObject::Initialize()
{
	for (Component* comp : mComponents)
	{
		comp->Initialize();
	}
}

void Game::GameObject::Update()
{
	for (Component* comp : mComponents)
	{
		comp->Update();
	}
}

void Game::GameObject::LateUpdate()
{
	for (Component* comp : mComponents)
	{
		comp->LateUpdate();
	}
}

void Game::GameObject::Render(HDC hdc)
{
	for (Component* comp : mComponents)
	{
		comp->Render(hdc);
	}
}

void Game::GameObject::InitializeTransform()
{
	AddComponent<Transform>();
}

