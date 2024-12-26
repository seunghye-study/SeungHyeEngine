#include "Projectile.h"

Projectile::Projectile(UINT sX, UINT sY)
	:mX(sX),
	mY(sY)
{

}

Projectile::~Projectile()
{
}

void Projectile::Update()
{
	mX += 1.0f;
}

void Projectile::LateUpdate()
{
}

void Projectile::Render(HDC hdc)
{
	Ellipse(hdc, 10, 10, 20, 20);
}
