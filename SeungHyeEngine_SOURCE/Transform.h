#pragma once
#include "Entity.h"
#include "Component.h"

namespace Game
{
	struct Pos
	{
		int mX;
		int mY;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(int x, int y) { mX = x; mY = y; }
		int GetPosX() { return mX; }
		int GetPosY() { return mY; }

	private:
		int mX;
		int mY;
	};

}

