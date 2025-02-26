#include "PlayerScript.h"
#include "GameInput.h"
#include "Transform.h"
#include "GameTime.h"
#include "GameObject.h"
#include "Animator.h"
#include "../SeungHyeEngine_STATIC/Cat.h"
#include "../SeungHyeEngine_STATIC/CatScript.h"
#include <Object.h>
#include <Resources.h>

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
	case PlayerScript::eState::GiveWater:
		GiveWater();
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

void Game::PlayerScript::AttackEffect()
{
	Game::Cat* cat = Game::Instantiate<Game::Cat>(Game::eLayerType::Animal);
	cat->AddComponent<Game::CatScript>();

	Game::Texture* catTex = Game::Resources::Find<Texture>(L"Cat");
	Game::Animator* catAnimator = cat->AddComponent<Animator>();
	catAnimator->CreateAnimation(L"DownWalk", catTex
		, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"RightWalk", catTex
		, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"UpWalk", catTex
		, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"LeftWalk", catTex
		, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"SitDown", catTex
		, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"Grooming", catTex
		, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	catAnimator->CreateAnimation(L"LayDown", catTex
		, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

	catAnimator->PlayAnimation(L"SitDown", false);
	cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
	cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
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

	if (GameInput::GetKey(eKeyCode::LButton))
	{
		mState = PlayerScript::eState::GiveWater;
		mAnimator->PlayAnimation(L"GiveWaterFront", false);
		Vector2 mousePos = Game::GameInput::GetMousePosition();
	}
}

void Game::PlayerScript::GiveWater()
{
	if (mAnimator->IsComplete())
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"Idle", false);
	}
}
