#include "Application.h"


// 생성자, 초기화
App::Application::Application()
	: mHwnd(nullptr),
	mHdc(nullptr),
	mSpeed(0.0f),
	mX(0.0f),
	mY(0.0f)
{
}

App::Application::~Application()
{
}

void App::Application::Initialize(HWND hwnd)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
}

void App::Application::Run()
{
	Update();
	LateUpdate();
	Render();
}

void App::Application::Update()
{
	mSpeed += 0.01f;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mX -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mX += 0.01f;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mY -= 0.01f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		mY += 0.01f;
	}
}

void App::Application::LateUpdate()
{
}

void App::Application::Render()
{
	// 그리기
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

	Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

	SelectObject(mHdc, oldBrush);
	DeleteObject(blueBrush);
}
