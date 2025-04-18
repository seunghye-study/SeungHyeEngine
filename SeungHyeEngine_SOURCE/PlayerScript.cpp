#include "PlayerScript.h"
#include "GameInput.h"
#include "Transform.h"
#include "GameTime.h"
#include "GameObject.h"
#include "Animator.h"
#include "RigidBody.h"


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
	case Game::PlayerScript::eState::Move:
		Move();
		break;
	case Game::PlayerScript::eState::Idle:
		Idle();
		break;
	case Game::PlayerScript::eState::IdleLeft:
		Idle();
		break;
	case Game::PlayerScript::eState::IdleRight:
		Idle();
		break;
	case Game::PlayerScript::eState::IdleUp:
		Idle();
		break;
	case Game::PlayerScript::eState::GiveWaterFront:
		GiveWater();
		break;
	case Game::PlayerScript::eState::GiveWaterLeft:
		GiveWater();
		break;
	case Game::PlayerScript::eState::GiveWaterRight:
		GiveWater();
		break;
	case Game::PlayerScript::eState::GiveWaterUp:
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

void Game::PlayerScript::OnCollisionEnter(Collider* other)
{
	if (other->GetOwner()->GetLayerType() == eLayerType::BackGround)
	{
		GetOwner()->GetComponent<RigidBody>()->SetVelocity(Vector2::Zero);// 충돌 시 정지
	}
}

void Game::PlayerScript::OnCollisionStay(Collider* other)
{
	if (other->GetOwner()->GetLayerType() == eLayerType::BackGround)
	{
		GetOwner()->GetComponent<RigidBody>()->SetVelocity(Vector2::Zero);// 충돌 시 정지
	}
}

void Game::PlayerScript::OnCollisionExit(Collider* other)
{
}

void Game::PlayerScript::Move()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	RigidBody* rb = GetOwner()->GetComponent<RigidBody>();
	Vector2 velocity = Vector2::Zero;

	if (GameInput::GetKey(eKeyCode::A))
	{
		//pos.x -= 200.0f * Time::DeltaTime();
		//tr->SetPosition(pos);
		//rb->AddForce(Vector2(-200.0f, 0.0f));
		velocity.x = -200.0f;
	}
	if (GameInput::GetKey(eKeyCode::D))
	{
		/*pos.x += 200.0f * Time::DeltaTime();
		tr->SetPosition(pos);*/
		//rb->AddForce(Vector2(200.0f, 0.0f));
		velocity.x = 200.0f;
	}
	if (GameInput::GetKey(eKeyCode::S))
	{
		/*pos.y += 200.0f * Time::DeltaTime();
		tr->SetPosition(pos);*/
		//rb->AddForce(Vector2(0.0f, -200.0f));
		velocity.y = 200.0f;
	}
	if (GameInput::GetKey(eKeyCode::W))
	{
		/*pos.y -= 200.0f * Time::DeltaTime();
		tr->SetPosition(pos);*/
		//rb->AddForce(Vector2(0.0f, 200.0f));
		velocity.y = -200.0f;
	}

	rb->SetVelocity(velocity);

	if (GameInput::GetKeyUp(eKeyCode::D))
	{
		mState = PlayerScript::eState::IdleRight;
		mAnimator->PlayAnimation(L"RightIdle", false);
	}
	if (GameInput::GetKeyUp(eKeyCode::A))
	{
		mState = PlayerScript::eState::IdleLeft;
		mAnimator->PlayAnimation(L"LeftIdle", false);
	}
	if (GameInput::GetKeyUp(eKeyCode::W))
	{
		mState = PlayerScript::eState::IdleUp;
		mAnimator->PlayAnimation(L"UpIdle", false);
	}
	if (GameInput::GetKeyUp(eKeyCode::S)) // 앞
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
		switch (mState)
		{
		case Game::PlayerScript::eState::Idle:
			mState = PlayerScript::eState::GiveWaterFront;
			mAnimator->PlayAnimation(L"GiveWaterFront", false);
			break;
		case Game::PlayerScript::eState::IdleLeft:
			mState = PlayerScript::eState::GiveWaterLeft;
			mAnimator->PlayAnimation(L"GiveWaterLeft", false);
			break;
		case Game::PlayerScript::eState::IdleRight:
			mState = PlayerScript::eState::GiveWaterRight;
			mAnimator->PlayAnimation(L"GiveWaterRight", false);
			break;
		case Game::PlayerScript::eState::IdleUp:
			mState = PlayerScript::eState::GiveWaterUp;
			mAnimator->PlayAnimation(L"GiveWaterUp", false);
			break;
		default:
			break;
		}
	}
}

void Game::PlayerScript::GiveWater()
{
	if (mAnimator->IsComplete())
	{
		switch (mState)
		{
		case Game::PlayerScript::eState::GiveWaterFront:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
			break;
		case Game::PlayerScript::eState::GiveWaterLeft:
			mState = eState::IdleLeft;
			mAnimator->PlayAnimation(L"LeftIdle", false);
			break;
		case Game::PlayerScript::eState::GiveWaterRight:
			mState = eState::IdleRight;
			mAnimator->PlayAnimation(L"RightIdle", false);
			break;
		case Game::PlayerScript::eState::GiveWaterUp:
			mState = eState::IdleUp;
			mAnimator->PlayAnimation(L"UpIdle", false);
			break;
		default:
			break;
		}
		
	}
}
