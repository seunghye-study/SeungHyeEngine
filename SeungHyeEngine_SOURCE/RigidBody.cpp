#include "RigidBody.h"
#include "GameTime.h"
#include "Transform.h"
#include "GameObject.h"

Game::RigidBody::RigidBody() : Component(eComponentType::Rigidbody)
, mMass(1.0f)
, mFriction(10.0f)
, mForce(Vector2::Zero)
, mVelocity(Vector2::Zero)
, mGravity(Vector2(0.0f, 800.0f))
, mAccelation(Vector2::Zero)
, mbGround(false)
, mLimitedVelocity(Vector2(200.0f, 200.0f))
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
	// todo : �߷�, �ӵ����� �ڵ� ����

	// F = MA
	mAccelation = mForce / mMass;
	mVelocity += mAccelation * Game::Time::DeltaTime();
	
	//�ִ� �ӵ� ����
	Vector2 gravity = mGravity;
	gravity.normalize();
	float dot = Vector2::Dot(mVelocity, gravity);
	gravity = gravity * dot;

	if (!(mVelocity == Vector2::Zero))
	{
		Vector2 friction = -mVelocity;
		friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

		if (mVelocity.length() <= friction.length())
		{
			mVelocity = Vector2::Zero; // ����
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
