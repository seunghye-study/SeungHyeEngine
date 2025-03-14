#pragma once
#include "Resource.h"

namespace Game
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			bmp,
			png,
			None,
		};

		Texture();
		~Texture();

		static Texture* Create(const std::wstring& name, UINT width, UINT height);
		virtual HRESULT Load(const std::wstring& path) override;


		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		void SetWidth(UINT width) { mWidth = width; }
		void SetHeight(UINT height) { mHeight = height; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		bool mAlpha;
		eTextureType mType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}

