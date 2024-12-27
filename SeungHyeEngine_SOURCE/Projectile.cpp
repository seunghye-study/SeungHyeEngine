#include "Projectile.h"

Projectile::Projectile(UINT sX, UINT sY)
	:mX(sX),
	mY(sY),
	mSpeed(0.3f)
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
	Ellipse(hdc, 10, 10, 20, 20);
}

