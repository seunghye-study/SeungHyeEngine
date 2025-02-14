#include "PlayerScript.h"
#include "GameInput.h"
#include "Transform.h"
#include "GameTime.h"
#include "GameObject.h"
#include "Animator.h"


Game::PlayerScript::PlayerScript()
	:mState(PlayerScript::eState::Idle)
	,mAnimator(nullptr)
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
	if (mAnimator == nullptr)
	{
		mAnimator = GetOwner()->GetComponent<Animator>();
	}

	switch (mState)
	{
	case PlayerScript::eState::Move:
		Move();
		break;
	case PlayerScript::eState::Idle:
		Idle();
		break;
	default:
		break;
	}
}

void Game::PlayerScript::LateUpdate()
{

}

void Game::PlayerScript::Render(HDC hdc)
{

}

void Game::PlayerScript::Move()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	if (GameInput::GetKey(eKeyCode::A))
	{
		pos.x -= 100.0f * Time::DeltaTime();
		tr->SetPosition(pos);
	}
	if (GameInput::GetKey(eKeyCode::D))
	{
		pos.x += 100.0f * Time::DeltaTime();
		tr->SetPosition(pos);
	}
	if (GameInput::GetKey(eKeyCode::S))
	{
		pos.y += 100.0f * Time::DeltaTime();
		tr->SetPosition(pos);
	}
	if (GameInput::GetKey(eKeyCode::W))
	{
		pos.y -= 100.0f * Time::DeltaTime();
		tr->SetPosition(pos);
	}

	// key up
	// TODO : 멈춘 방향 보고 서있도록 분리하기.
	if (GameInput::GetKeyUp(eKeyCode::D) || GameInput::GetKeyUp(eKeyCode::A)
		|| GameInput::GetKeyUp(eKeyCode::W) || GameInput::GetKeyUp(eKeyCode::S))
	{
		mState = PlayerScript::eState::Idle;
		mAnimator->PlayAnimation(L"Idle", false);
	}
}

void Game::PlayerScript::Idle()
{
	if (GameInput::GetKey(eKeyCode::A))
	{
		mState = PlayerScript::eState::Move;
		mAnimator->PlayAnimation(L"GoLeft");
	}
	if (GameInput::GetKey(eKeyCode::D))
	{
		mState = PlayerScript::eState::Move;
		mAnimator->PlayAnimation(L"GoRight");
	}
	if (GameInput::GetKey(eKeyCode::S))
	{
		mState = PlayerScript::eState::Move;
		mAnimator->PlayAnimation(L"GoDown");
	}
	if (GameInput::GetKey(eKeyCode::W))
	{
		mState = PlayerScript::eState::Move;
		mAnimator->PlayAnimation(L"GoUp");
	}
		
}
