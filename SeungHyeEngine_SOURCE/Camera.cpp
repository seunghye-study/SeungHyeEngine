#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"
#include "Application.h"

extern Game::Application application;

Game::Camera::Camera()
	: Component(eComponentType::Camera)
	, mDistance(GameMath::Vector2::Zero)
	, mResolution(GameMath::Vector2::Zero)
	, mLookPosition(GameMath::Vector2::Zero)
	, mTarget(nullptr)
{
}

Game::Camera::~Camera()
{
}

void Game::Camera::Initialize()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
}

void Game::Camera::Update()
{
	if (mTarget)
	{
		Transform* tr = mTarget->GetComponent<Transform>();
		mLookPosition = tr->GetPosition();
	}
	else
	{
		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();
	}
	mDistance = mLookPosition - (mResolution / 2.0f);
}

void Game::Camera::LateUpdate()
{
}

void Game::Camera::Render(HDC hdc)
{
}
