#pragma once
#include "CommonInclude.h"
#include "Entity.h"
#include "Component.h"

namespace Game
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void ImageLoad(const std::wstring& path);
		void SetScale(float scaleX, float scaleY);
	private:
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
		float mScaleX;
		float mScaleY;
		
	};
}


