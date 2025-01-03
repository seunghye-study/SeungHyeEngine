#pragma once

#include "CommonInclude.h"
#include "Projectile.h"

namespace Game
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		void fire();

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;

		std::vector<Projectile*> mProjectile;
	};


}


