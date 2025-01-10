#pragma once
#include "GameObject.h"

namespace Game
{
	class GamePlayer : public GameObject
	{
	public:
		GamePlayer();
		~GamePlayer();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		} 

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;
	};
}


