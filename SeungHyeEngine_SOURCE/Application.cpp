#include "Application.h"
#include "GameInput.h"
#include "GameTime.h"
#include "SceneManager.h"
#include "Resources.h"
#include "CollisionManager.h"

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
	CollisionManager::Initialize();
	SceneManager::Initialize();
}

void Game::Application::Run()
{
	Update();
	LateUpdate();
	Render();
	Destroy();
}

void Game::Application::Release()
{
	SceneManager::Release();
	Resources::Release();
}

void Game::Application::Update()
{
	GameInput::Update();
	Time::Update();
	CollisionManager::Update();
	SceneManager::Update();
}

void Game::Application::LateUpdate()
{
	CollisionManager::LateUpdate();
	SceneManager::LateUpdate();
}

void Game::Application::Render()
{
	ClearRenderTarget();

	Time::Render(mBackHdc);
	CollisionManager::Render(mBackHdc);
	SceneManager::Render(mBackHdc);

	CopyRenderTarget(mBackHdc, mHdc);
}

void Game::Application::Destroy()
{

}

void Game::Application::ClearRenderTarget()
{
	HBRUSH backgroundBrush = CreateSolidBrush(RGB(0, 0, 0)); // 배경색 (검정)
	RECT rect = { 0, 0, mWidth, mHeight };
	FillRect(mBackHdc, &rect, backgroundBrush);
	DeleteObject(backgroundBrush);
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
}

void Game::Application::InitComponent()
{
	GameInput::Initialize();
	Time::Initialize();
}