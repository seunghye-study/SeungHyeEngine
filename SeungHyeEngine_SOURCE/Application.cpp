#include "Application.h"
#include "GameInput.h"
#include "GameTime.h"
#include "SceneManager.h"

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
	InitComponent();

	SceneManager::Initialize();
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
	mGamePlayer.Update();
	SceneManager::Update();
}

void Game::Application::LateUpdate()
{

}

void Game::Application::Render()
{
	ClearRenderTarget();
	Time::Render(mHdc);
	SceneManager::Render(mHdc);
	CopyRenderTarget(mBackHdc, mHdc);
}

void Game::Application::ClearRenderTarget()
{
	Rectangle(mBackHdc, 0, 0, 1600, 900);
}

void Game::Application::CopyRenderTarget(HDC source, HDC dest)
{
	BitBlt(dest, 0, 0, mWidth, mHeight
		, source, 0, 0, SRCCOPY);
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