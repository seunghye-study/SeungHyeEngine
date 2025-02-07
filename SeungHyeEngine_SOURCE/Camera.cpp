#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"
#include "Application.h"

extern Game::Application app;

Game::Camera::Camera()
	: Component(eComponentType::Camera)
	, mDistance(Vector2::Zero)
	, mResolution(Vector2::Zero)
	, mLookPosition(Vector2::Zero)
	, mTarget(nullptr)
{
}

Game::Camera::~Camera()
{
}

void Game::Camera::Initialize()
{
	mResolution.x = app.GetWidth();
	mResolution.y = app.GetHeight();
}

void Game::Camera::Update()
{
	if (mTarget)
	{
		Transform* tr = mTarget->GetComponent<Transform>();
		mLookPosition = tr->GetPosition();
	}
	Transform* cameraTr = GetOwner()->GetComponent<Transform>();
	mLookPosition = cameraTr->GetPosition();

	mDistance = mLookPosition - (mResolution / 2.0f);
}

void Game::Camera::LateUpdate()
{
}

void Game::Camera::Render(HDC hdc)
{
}
