#pragma once

#include "CommonInclude.h"
#include "GameObject.h"
#include "GamePlayer.h"

namespace Game {
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		/* Scene °ü¸®? */
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);

		/*Adgustment*/
		void AdjustWindow(HWND hwnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);
		void InitComponent();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		std::vector<Scene*> mScenes;
		GamePlayer mGamePlayer;
	};
}


