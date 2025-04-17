#include "Collider.h"
#include "GameObject.h"
#include "Script.h"

namespace Game
{
	UINT Collider::CollisionID = 1;

	Collider::Collider(eColliderType type) : Component(eComponentType::Collider)
		, mType(type)
		, mID(CollisionID++)
		, mSize(Vector2::One)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render(HDC hdc)
	{
		//Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y);
	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if (script)
		{
			script->OnCollisionEnter(other);
		}
	}
	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if(script)
			script->OnCollisionExit(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if(script)
			script->OnCollisionStay(other);
	}
}