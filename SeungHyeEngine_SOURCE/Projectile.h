#pragma once
#include "CommonInclude.h"

class Projectile
{
public:
	Projectile(float x, float y);
	~Projectile();

	void Update();
	void LateUpdate();
	void Render(HDC hdc);

private:
	float mX;
	float mY;

	float mSpeed;
};

