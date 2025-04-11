#include "TilemapRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

// 정적 멤버 변수 정의
Vector2 Game::TilemapRenderer::TileSize = Vector2::One;
Vector2 Game::TilemapRenderer::OriginTileSize = Vector2::One;
Vector2 Game::TilemapRenderer::SelectedIndex = Vector2(-1.0f, -1.0f);

Game::TilemapRenderer::TilemapRenderer() : Component(eComponentType::SpriteRenderer)
	, mTexture(nullptr)
	, mSize(3.0f, 3.0f)
	, mIndex(0, 0)
	, mTileSize(16.0f, 16.0f)
{

}

Game::TilemapRenderer::~TilemapRenderer()
{
}

void Game::TilemapRenderer::Initialize()
{
}

void Game::TilemapRenderer::Update()
{
}

void Game::TilemapRenderer::LateUpdate()
{


}

void Game::TilemapRenderer::Render(HDC hdc)
{
	if (mTexture == nullptr) // 텍스처 세팅
	{
		assert(false);
	}

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	float rot = tr->GetRotation();
	Vector2 scale = tr->GetScale();
	pos = mainCamera->CalculatePosition(pos);
	if (mTexture->GetTextureType() == Texture::eTextureType::bmp)
	{
		if (mTexture->IsAlpha())
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;

			AlphaBlend(hdc, pos.x, pos.y, mTileSize.x*mSize.x*scale.x
				,mTileSize.y*mSize.y*scale.y, mTexture->GetHdc()
				, mIndex.x*mTileSize.x, mIndex.y*mTileSize.y, mTileSize.x, mTileSize.y, func);
		}
		else // alpha 채널이 없을 때
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTileSize.x * mSize.x * scale.x, mTileSize.y * mSize.y * scale.y
				, mTexture->GetHdc()
				, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
				, mTileSize.x, mTileSize.y, RGB(255, 0, 255));
		}
	}
	else if(mTexture->GetTextureType() == Texture::eTextureType::png)
	{

	}
}
