#include "Animation.h"
#include "GameTime.h"
#include "Transform.h"
#include "GameObject.h"
#include "Animator.h"
#include "Renderer.h"
#include "Camera.h"

Game::Animation::Animation() : Resource(Game::eResourceType::Animation),
	mAnimator(nullptr),
	mTexture(nullptr),
	mAnimationSheet{},
	mIndex(-1),
	mTime(0.0f),
	mComplete(false)
{
}

Game::Animation::~Animation()
{
}

HRESULT Game::Animation::Load(const std::wstring& path)
{
	return E_NOTIMPL;
}

void Game::Animation::Update()
{
	if (mComplete) return;

	mTime += Game::Time::DeltaTime();

	if (mAnimationSheet[mIndex].duration < mTime)
	{
		mTime = 0.0f;
		if (mIndex < mAnimationSheet.size() - 1)
			mIndex++;
		else
			mComplete = true;
	}
}

void Game::Animation::Render(HDC hdc)
{
	if (mTexture == nullptr) return;

	GameObject* gameObj = mAnimator->GetOwner();
	Transform* tr = gameObj->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	float rot = tr->GetRotation();
	Vector2 scale = tr->GetScale();

	if (Game::mainCamera)
		pos = Game::mainCamera->CalculatePosition(pos);

	Sprite sprite = mAnimationSheet[mIndex];
	Texture::eTextureType type = mTexture->GetTextureType();
	if (type == Texture::eTextureType::bmp)
	{
		HDC imgHdc = mTexture->GetHdc();

		if (mTexture->IsAlpha())
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;
			AlphaBlend(hdc, pos.x, pos.y, sprite.size.x * scale.x, sprite.size.y * scale.y, imgHdc,
				sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
		}
		else
		{
			TransparentBlt(hdc
				, pos.x - (sprite.size.x / 2.0f)
				, pos.y - (sprite.size.y / 2.0f)
				, sprite.size.x * scale.x
				, sprite.size.y * scale.y
				, imgHdc
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, RGB(255, 0, 255));
		}

	}
	else if (type == Texture::eTextureType::png)
	{
		Gdiplus::ImageAttributes imgAtt = {};

		imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
		Gdiplus::Graphics graphics(hdc);

		graphics.TranslateTransform(pos.x, pos.y);
		graphics.RotateTransform(rot);
		graphics.TranslateTransform(-pos.x, -pos.y);

		graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(
			pos.x - (sprite.size.x / 2.0f),
			pos.y - (sprite.size.y / 2.0f),
			sprite.size.x * scale.x,
			sprite.size.y * scale.y
		), sprite.leftTop.x
			, sprite.leftTop.y
			, sprite.size.x
			, sprite.size.y
			, Gdiplus::UnitPixel
			, nullptr);
	}
}

void Game::Animation::CreateAnimation(const std::wstring& name, Game::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
{
	mTexture = spriteSheet;

	for (size_t i = 0; i < spriteLength; i++)
	{
		Sprite sprite = {};
		sprite.leftTop.x = leftTop.x + (size.x * i);
		sprite.leftTop.y = leftTop.y;
		sprite.size = size;
		sprite.offset = offset;
		sprite.duration = duration;

		mAnimationSheet.push_back(sprite);
	}
}

void Game::Animation::Reset()
{
	mTime = 0.0f;
	mIndex = 0;
	mComplete = false;
}
