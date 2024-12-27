#pragma once
#include "CommonInclude.h"

class Monster
{
public:
	Monster();
	~Monster();

	void Update();
	void LateUpdate();
	void Render(HDC hdc);

	void SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}
	bool IsChangedDirection() const;

private:
	float mX;
	float mY;
	float mSpeed;

	bool flag = true;
	

};

