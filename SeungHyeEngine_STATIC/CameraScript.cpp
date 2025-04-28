#include "CameraScript.h"
#include "GameInput.h"
#include "Transform.h"
#include "GameTime.h"
#include "GameObject.h"
#include "Animator.h"
#include "Cat.h"
#include "CatScript.h"
#include "SObject.h"
#include "Resources.h"


Game::CameraScript::CameraScript()
{
}

Game::CameraScript::~CameraScript()
{
}

void Game::CameraScript::Initialize()
{
}

void Game::CameraScript::Update()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	if (GameInput::GetKey(eKeyCode::Right))
	{
		pos.x += 150.0f * Time::DeltaTime();
	}
	if (GameInput::GetKey(eKeyCode::Left))
	{
		pos.x -= 150.0f * Time::DeltaTime();
	}
	if (GameInput::GetKey(eKeyCode::Up))
	{
		pos.y -= 150.0f * Time::DeltaTime();
	}
	if (GameInput::GetKey(eKeyCode::Down))
	{
		pos.y += 150.0f * Time::DeltaTime();
	}

	tr->SetPosition(pos);
}

void Game::CameraScript::LateUpdate()
{
}

void Game::CameraScript::Render(HDC hdc)
{
}
