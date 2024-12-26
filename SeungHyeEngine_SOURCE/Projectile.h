#pragma once
#include "CommonInclude.h"
#include <GameObject.h>

class Projectile
{
public:
	Projectile(UINT sX, UINT sY);
	~Projectile();

	void Update();
	void LateUpdate();
	void Render(HDC hdc);

private:
	float mX;
	float mY;

};

