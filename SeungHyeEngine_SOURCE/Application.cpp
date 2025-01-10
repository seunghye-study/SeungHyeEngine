#include "Application.h"
#include "GameInput.h"
#include "GameTime.h"

using namespace Game;

// 생성자, 초기화
Game::Application::Application()
	: mHwnd(nullptr),
	mHdc(nullptr),
	mWidth(0),
	mHeight(0),
	mBackBitmap(nullptr),
	mBackHdc(nullptr)
{

}

Game::Application::~Application()
{
}

void Game::Application::Initialize(HWND hwnd, UINT width, UINT height)
{
	AdjustWindow(hwnd, width, height);
	CreateBuffer(width, height);
	mPlayer.SetPosition(0.0f, 0.0f);
	InitComponent();
}

void Game::Application::Run()
{
	Update();
	LateUpdate();
	Render();
}

void Game::Application::Update()
{
	GameInput::Update();
	Time::Update();
	mPlayer.Update();
	mMonster.Update();
}

void Game::Application::LateUpdate()
{
	mPlayer.LateUpdate();
	mMonster.LateUpdate();
}

void Game::Application::Render()
{
	Rectangle(mBackHdc, 0, 0, 1600, 900);
	
	Time::Render(mHdc);
	mPlayer.Render(mHdc);
	mMonster.Render(mHdc);

	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0,0,SRCCOPY);
}


void Game::Application::AdjustWindow(HWND hwnd, UINT width, UINT height)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);

	RECT rect = { 0,0, width, height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	mWidth = rect.right - rect.left;
	mHeight = rect.bottom - rect.top;

	SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
	ShowWindow(mHwnd, true);
}

void Game::Application::CreateBuffer(UINT width, UINT height)
{
	mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
	mBackHdc = CreateCompatibleDC(mHdc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
	DeleteObject(oldBitmap);
}

void Game::Application::InitComponent()
{
	GameInput::Initialize();
	Time::Initialize();
}