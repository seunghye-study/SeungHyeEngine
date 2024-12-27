#include "Projectile.h"

Projectile::Projectile(float x, float y)
	:mX(x),
	mY(y),
	mSpeed(1.0f)
{

}

Projectile::~Projectile()
{
}

void Projectile::Update()
{
	mX += mSpeed;
}

void Projectile::LateUpdate()
{
}

void Projectile::Render(HDC hdc)
{
	HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, greenBrush);

	Ellipse(hdc, static_cast<int>(mX) - 5, static_cast<int>(mY) - 5, static_cast<int>(mX) + 5, static_cast<int>(mY) + 5); // ÃÑ¾Ë Å©±â: 10x10

	SelectObject(hdc, oldBrush);
	DeleteObject(greenBrush);
}
