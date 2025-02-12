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
	// 알파블렌드 조건 : 알파채널 존재(r g b a)
	if (mTexture == nullptr) return;

	GameObject* gameObj = mAnimator->GetOwner();
	Transform* tr = gameObj->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	if (Game::mainCamera)
		pos = Game::mainCamera->CalculatePosition(pos);

	BLENDFUNCTION func = {};
	func.BlendOp = AC_SRC_OVER;
	func.BlendFlags = 0;
	func.AlphaFormat = AC_SRC_ALPHA;
	func.SourceConstantAlpha = 125;

	Sprite sprite = mAnimationSheet[mIndex];
	HDC imgHdc = mTexture->GetHdc();

	AlphaBlend(hdc, pos.x, pos.y, sprite.size.x * 5, sprite.size.y * 5, imgHdc,
		sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
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
