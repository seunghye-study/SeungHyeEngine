#pragma once
#include "Entity.h"
#include "Component.h"
#include "SMath.h"

namespace Game
{
	using namespace GameMath;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { mPosition=pos; }
		Vector2 GetPosition() { return mPosition; }
		void SetScale(Vector2 scale) { mScale=scale; }
		Vector2 GetScale() { return mScale; }
		void SetRotation(float rotation) { mRotation = rotation; }
		float GetRotation() { return mRotation; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};

}

