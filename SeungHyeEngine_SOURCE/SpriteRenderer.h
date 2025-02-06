#pragma once
#include "CommonInclude.h"
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

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

		void SetTexture(Texture* texture) { mTexture = texture; }
		void SetSize(GameMath::Vector2 size) { mSize = size; }


	private:
		Texture* mTexture;
		GameMath::Vector2 mSize;
	};
}


