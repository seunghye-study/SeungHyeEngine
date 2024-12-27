#pragma once

#include "CommonInclude.h"
#include "GameObject.h"
#include "Projectile.h"
#include "Monster.h"

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
		HWND mHwnd;
		HDC mHdc;

		// dc+bitmap ÇÑ¼¼Æ®
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;
		Monster mMonster;
	};
}


