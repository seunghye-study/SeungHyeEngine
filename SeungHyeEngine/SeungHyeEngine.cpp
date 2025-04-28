// SeungHyeEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "SeungHyeEngine.h"
#include "../SeungHyeEngine_SOURCE/Application.h"
#include "../SeungHyeEngine_SOURCE/LoadScene.h"
#include "../SeungHyeEngine_SOURCE/LoadResources.h"
#include "../SeungHyeEngine_SOURCE/Resources.h"
#include "../SeungHyeEngine_SOURCE/Texture.h"
#include "../SeungHyeEngine_STATIC/ToolScene.h"
#include "../SeungHyeEngine_SOURCE/SceneManager.h"


Game::Application application;

ULONG_PTR gpToken;
Gdiplus::GdiplusStartupInput gpsi;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

ATOM                MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc); // intance = 윈도우 id, 윈도우가 여러개 생길수도 있으니까
BOOL                InitInstance(HINSTANCE, int);
BOOL                InitToolScene(HINSTANCE);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SEUNGHYEENGINE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance, szWindowClass, WndProc);
    MyRegisterClass(hInstance, L"TileMap", Game::ToolScene::TileProc);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SEUNGHYEENGINE));

    MSG msg;

    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
            {
                break;
            }
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            application.Run();
        }
    }

    Gdiplus::GdiplusShutdown(gpToken);
    application.Release();
    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = proc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SEUNGHYEENGINE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = name;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, 900, 600, nullptr, nullptr, hInstance, nullptr); // window create, window 정보를 바탕으로 생성, 핸들 반환
   HWND ToolhWnd = CreateWindowW(L"TileMap", L"TileMap", WS_OVERLAPPEDWINDOW,
       0, 0, 900, 600, nullptr, nullptr, hInstance, nullptr);

   Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);
   
   Game::LoadResources();
   //Game::LoadScenes();

   application.Initialize(hWnd, 1280, 720);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   ShowWindow(ToolhWnd, nCmdShow);
   UpdateWindow(ToolhWnd);

   Game::LoadToolScene();
   
   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


BOOL InitToolScene(HINSTANCE hInstance)
{
    Game::Scene* activeScene = Game::SceneManager::GetActiveScene();
    std::wstring name = activeScene->GetName();

    if (name == L"ToolScene")
    {
        HWND ToolHWnd = CreateWindowW(L"TILEWINDOW", L"TileWindow", WS_OVERLAPPEDWINDOW,
            0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

        Game::Texture* texture = Game::Resources::Find<Game::Texture>(L"FarmSheet");

        RECT rect = { 0, 0, texture->GetWidth(), texture->GetHeight() };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        UINT toolWidth = rect.right - rect.left;
        UINT toolHeight = rect.bottom - rect.top;

        SetWindowPos(ToolHWnd, nullptr, 672, 0, toolWidth, toolHeight, 0);
        ShowWindow(ToolHWnd, true);
        UpdateWindow(ToolHWnd);
    }

    return TRUE;
}