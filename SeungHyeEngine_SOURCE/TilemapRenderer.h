#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"


namespace Game
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(Texture* texture) { mTexture = texture; }
		void SetSize(GameMath::Vector2 size) { mSize = size; }
		void SetIndex(Vector2 index) { mIndex = index; }


	public:
		static Vector2 TileSize;
		static Vector2 SelectedIndex;
		static Vector2 OriginTileSize;

	private:
		Vector2 mTileSize;
		Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
	};
}


