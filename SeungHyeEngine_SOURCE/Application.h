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

		/*Getter*/
		HDC GetHDC() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

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


