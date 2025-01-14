#pragma once

#include "CommonInclude.h"

namespace Game
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

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


