#include "PlayerScript.h"
#include "GameInput.h"
#include "Transform.h"
#include "GameTime.h"
#include "GameObject.h"


Game::PlayerScript::PlayerScript()
{

}


Game::PlayerScript::~PlayerScript()
{

}

void Game::PlayerScript::Initialize()
{

}

void Game::PlayerScript::Update()
{
	//if (GameInput::GetKey(eKeyCode::Right))
	//{
	//	Transform* tr = GetOwner()->GetComponent<Transform>();
	//	Vector2 pos = tr->GetPosition();
	//	pos.x += 100.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//if (GameInput::GetKey(eKeyCode::Left))
	//{
	//	Transform* tr = GetOwner()->GetComponent<Transform>();
	//	Vector2 pos = tr->GetPosition();
	//	pos.x -= 100.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//if (GameInput::GetKey(eKeyCode::Up))
	//{
	//	Transform* tr = GetOwner()->GetComponent<Transform>();
	//	Vector2 pos = tr->GetPosition();
	//	pos.y -= 100.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
	//if (GameInput::GetKey(eKeyCode::Down))
	//{
	//	Transform* tr = GetOwner()->GetComponent<Transform>();
	//	Vector2 pos = tr->GetPosition();
	//	pos.y += 100.0f * Time::DeltaTime();
	//	tr->SetPosition(pos);
	//}
}

void Game::PlayerScript::LateUpdate()
{

}

void Game::PlayerScript::Render(HDC hdc)
{

}
