#pragma once
#include "Component.h"

namespace Game
{
	using namespace GameMath;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }
		Vector2 CalculateTilePosition(Vector2 pos) { return pos + mDistance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; }

	private:
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;

	};
}



