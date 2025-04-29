#include "Transform.h"

Game::Transform::Transform() :
	Component(eComponentType::Transform),
	mScale(Vector2(1.0f, 1.0f)),
	mRotation(0.0f)
{
}

Game::Transform::~Transform()
{
}

void Game::Transform::Initialize()
{
}

void Game::Transform::Update()
{
}

void Game::Transform::LateUpdate()
{
}

void Game::Transform::Render(HDC hdc)
{
}
