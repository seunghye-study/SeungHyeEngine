#include "RigidBody.h"
#include "GameTime.h"
#include "Transform.h"
#include "GameObject.h"

Game::RigidBody::RigidBody() : Component(eComponentType::Rigidbody)
	, mMass(1.0f)
	, mFriction(10.0f)
	, mForce(Vector2::Zero)
	, mVelocity(Vector2::Zero)
	, mGravity(Vector2::Zero)
	, mAccelation(Vector2::Zero)
{

}

Game::RigidBody::~RigidBody()
{

}

void Game::RigidBody::Initialize()
{

}

void Game::RigidBody::Update()
{
	// F = MA
	mAccelation = mForce / mMass;
	mVelocity += mAccelation * Game::Time::DeltaTime();
	
	if (!(mVelocity == Vector2::Zero))
	{
		Vector2 friction = -mVelocity;
		friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

		if (mVelocity.length() <= friction.length())
		{
			mVelocity = Vector2::Zero; // ¸ØÃã
		}
		else
		{
			mVelocity += friction;
		}
	}

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	pos = pos + mVelocity * Time::DeltaTime();
	tr->SetPosition(pos);
	mForce.clear();
}

void Game::RigidBody::LateUpdate()
{
}

void Game::RigidBody::Render(HDC hdc)
{
}
