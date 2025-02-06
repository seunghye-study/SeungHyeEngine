#pragma once

#include "CommonInclude.h"
#include "Scene.h"

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

		/*HDC*/
		HDC GetHDC() { return mHdc; }

		/* Component */
		void InitComponent();

	private:

		/* Dubble buffering */
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);

		/*Adgustment*/
		void AdjustWindow(HWND hwnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);




	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		std::vector<Scene*> mScenes;
	};
}


