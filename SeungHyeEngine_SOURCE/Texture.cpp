#include "Texture.h"
#include "Application.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern Game::Application application;

Game::Texture::Texture() : Resource(Game::eResourceType::Texture)
{

}

Game::Texture::~Texture()
{

}

HRESULT Game::Texture::Load(const std::wstring& path)
{
	std::wstring ext = path.substr(path.find_last_of(L".") + 1);

	// bmp
	if (ext == L"bmp")
	{
		mType = eTextureType::bmp;
		mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		if (mBitmap == nullptr)
			return S_FALSE;

		BITMAP info = {};
		GetObject(mBitmap, sizeof(BITMAP), &info);

		mWidth = info.bmWidth;
		mHeight = info.bmHeight;

		HDC mainDC = application.GetHDC();
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(oldBitmap);
	}

	else if (ext == L"png")
	{
		mType = eTextureType::png;
		mImage = Gdiplus::Image::FromFile(path.c_str());
		if (mImage == nullptr)
			return S_FALSE;

		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}

	return S_OK;
}
