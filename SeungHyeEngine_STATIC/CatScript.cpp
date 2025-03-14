#include "CatScript.h"
#include "..\\SeungHyeEngine_SOURCE\GameInput.h"
#include "Transform.h"
#include "..\\SeungHyeEngine_SOURCE\GameTime.h"
#include "GameObject.h"
#include "Animator.h"

Game::CatScript::CatScript() 
	: mState(CatScript::eState::SitDown)
	,mAnimator(nullptr)
	, mTime(0.0f)
	, mDeathTime(0.0f)
{
}

Game::CatScript::~CatScript()
{
}

void Game::CatScript::Initialize()
{
}

void Game::CatScript::Update()
{
	mDeathTime += Time::DeltaTime();
	if (mDeathTime > 6.0f) 
	{

	}
	if (mAnimator == nullptr)
	{
		mAnimator = GetOwner()->GetComponent<Animator>();
	}

	switch (mState)
	{
	case CatScript::eState::SitDown:
		SitDown();
		break;
	case CatScript::eState::Walk:
		Move();
		break;
	case CatScript::eState::Sleep:
		break;
	case CatScript::eState::LayDown:
		LayDown();
		break;
	case CatScript::eState::Attack:
		break;
	default:
		break;
	}
}

void Game::CatScript::LateUpdate()
{
}

void Game::CatScript::Render(HDC hdc)
{
}

void Game::CatScript::SitDown()
{
	mTime += Time::DeltaTime();
	if (mTime > 2.0f)
	{
		mState = CatScript::eState::Walk;
		int direction = (rand() % 4);
		mDirection = (eDirection)direction;
		PlayWalkAnimationByDirection(mDirection);
		mTime = 0.0f;
	}
}

void Game::CatScript::Move()
{
	mTime += Time::DeltaTime();
	if (mTime > 2.0f)
	{
		bool isLayDown = (rand() % 2);
		if (isLayDown)
		{
			mState = CatScript::eState::LayDown;
			mAnimator->PlayAnimation(L"CatLayDown", false);
		}
		else
		{
			mState = CatScript::eState::SitDown;
			mAnimator->PlayAnimation(L"CatSitDown", false);
		}
	}
	Transform* tr = GetOwner()->GetComponent<Transform>();
	translate(tr);
}

void Game::CatScript::LayDown()
{
	mTime += Time::DeltaTime();
	if (mTime > 2.0f)
	{
		mState = CatScript::eState::SitDown;
		mAnimator->PlayAnimation(L"CatSitDown", false);
	}
	Transform* tr = GetOwner()->GetComponent<Transform>();
	translate(tr);
}

void Game::CatScript::PlayWalkAnimationByDirection(eDirection dir)
{
	switch (dir)
	{
	case CatScript::eDirection::Left:
		mAnimator->PlayAnimation(L"LeftWalk", true);
		break;
	case CatScript::eDirection::Right:
		mAnimator->PlayAnimation(L"RightWalk", true);
		break;
	case CatScript::eDirection::Down:
		mAnimator->PlayAnimation(L"DownWalk", true);
		break;
	case CatScript::eDirection::Up:
		mAnimator->PlayAnimation(L"UpWalk", true);
		break;
	default:
		assert(false);
		break;
	}
}

void Game::CatScript::translate(Transform* tr)
{
	Vector2 pos = tr->GetPosition();
	switch (mDirection)
	{
	case CatScript::eDirection::Left:
		pos.x -= 50.0f * Time::DeltaTime();
		break;
	case CatScript::eDirection::Right:
		pos.x += 50.0f * Time::DeltaTime();
		break;
	case CatScript::eDirection::Down:
		pos.y += 50.0f * Time::DeltaTime();
		break;
	case CatScript::eDirection::Up:
		pos.y -= 50.0f * Time::DeltaTime();
		break;
	default:
		assert(false);
		break;
	}
	tr->SetPosition(pos);
}
