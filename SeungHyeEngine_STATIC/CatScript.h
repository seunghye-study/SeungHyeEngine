#pragma once
#include "Script.h"
#include "Transform.h"
#include "SObject.h"

namespace Game
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};
		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void SetPlayer(GameObject* player) { mPlayer = player; }
		Vector2 mDest;

	private:
		void SitDown();
		void Move();
		void LayDown();

		void PlayWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
		float mDeathTime;
		GameObject* mPlayer;
		float mRadian;

	};
}


