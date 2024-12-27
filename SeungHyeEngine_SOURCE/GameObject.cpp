#include "GameObject.h"
#include "GameInput.h"
#include "Projectile.h"
#include <iostream>

Game::GameObject::GameObject()
	:mX(0.0f)
	, mY(0.0f)
{

}

Game::GameObject::~GameObject()
{

}

void Game::GameObject::Update()
{

	if ((GameInput::GetKey(EKeyCode::Left)))
	{
		mX -= 0.11f;
	}
	if ((GameInput::GetKey(EKeyCode::Right)))
	{
		mX += 0.11f;
	}

	if ((GameInput::GetKey(EKeyCode::Up)))
	{
		mY -= 0.11f;
	}

	if ((GameInput::GetKey(EKeyCode::Down)))
	{
		mY += 0.11f;
	}
	if ((GameInput::GetKey(EKeyCode::SpaceBar)))
	{
		//ÃÑ¾Ë¹ß»ç
		fire();
	}
	for (auto* projectile : mProjectile)
	{
		projectile->Update();
	}
}


void Game::GameObject::LateUpdate()
{
}

void Game::GameObject::Render(HDC hdc)
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

	SelectObject(hdc, oldBrush);
	DeleteObject(blueBrush);

	for (auto* projectile : mProjectile)
	{
		projectile->Render(hdc);
	}
}


void Game::GameObject::fire()
{
	mProjectile.push_back(new Projectile(mX+150, mY+150));
}
