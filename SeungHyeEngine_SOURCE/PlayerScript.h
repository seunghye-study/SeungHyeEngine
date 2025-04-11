#pragma once
#include "Script.h"


namespace Game
{
	class PlayerScript : public Script
	{
	public:
		enum class eDirection
		{

		};
		enum class eState
		{
			Move,
			Idle,
			IdleLeft,
			IdleRight,
			IdleUp,
			GiveWaterFront,
			GiveWaterLeft,
			GiveWaterRight,
			GiveWaterUp,
			Stop,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//collision
		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		void Move();
		void Idle();
		void GiveWater();

	private:
		eState mState;
		class Animator* mAnimator;


		/*startevent, endevent, complete event*/
	};
}


