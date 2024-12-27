#include "Monster.h"
#include <time.h>

Monster::Monster()
{
	// 시드설정
	mSpeed = 0.1f;
	srand(time(NULL));
	mX = rand() % 1200 + 100;
	mY = rand() % 600 + 50;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	if (mX <= 0) // 오른쪽으로 가야됨
		flag = true;
	if (mX >= 1300) // 왼쪽으로 가야됨
	{
		flag = false;
	}
	if (!flag)
		mX -= mSpeed;

	if (flag && mX < 1300)
		mX += mSpeed;
}

void Monster::LateUpdate()
{
}

void Monster::Render(HDC hdc)
{
	POINT point[3] = {
		{150 + mX, 50 + mY},  // 꼭대기 점
		{125 + mX, 100 + mY}, // 왼쪽 점
		{175+ mX, 100 + mY}  // 오른쪽 점
	};

	HBRUSH blueBrush = CreateSolidBrush(RGB(255, 0, 20));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	Polygon(hdc, point, 3);

	SelectObject(hdc, oldBrush);
	DeleteObject(blueBrush);
}

bool Monster::IsChangedDirection() const
{
	if (mX >= 1000 || mX <= 0)
	{
		return true;
	}
	return false;
}
