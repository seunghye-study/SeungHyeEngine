#pragma once
#include "Component.h"


namespace Game
{
	class Collider : public Component
	{
	public:
		Collider(eColliderType type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		
		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionExit(Collider* other);
		virtual void OnCollisionStay(Collider* other);

		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }

		UINT GetID() { return mID; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

		eColliderType GetColliderType() { return mType; }

	private:
		static UINT CollisionID;
		UINT mID;

		Vector2 mOffset;
		Vector2 mSize;
		eColliderType mType;
	};
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
