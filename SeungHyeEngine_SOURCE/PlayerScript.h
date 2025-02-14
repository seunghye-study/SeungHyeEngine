#pragma once
#include "Script.h"


namespace Game
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			//TODO : STOP ( ���� ���� �ٶ󺸰� ���ֱ� )
			Move,
			Idle
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void Move();
		void Idle();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}


