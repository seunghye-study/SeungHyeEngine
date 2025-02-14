#pragma once
#include "Script.h"


namespace Game
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			GoLeft,
			GoRight, 
			GoDown,
			GoUp,
			Wait
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		eState mState;
		class Animator* mAnimator;
	};
}


