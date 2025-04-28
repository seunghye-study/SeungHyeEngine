#include "Tile.h"
#include "TilemapRenderer.h"
#include "GameInput.h"
#include "GameTime.h"
#include "Transform.h"

void Game::Tile::Initialize()
{
	GameObject::Initialize();
}

void Game::Tile::Update()
{
	GameObject::Update();
}

void Game::Tile::LateUpdate()
{
	GameObject::LateUpdate();
}

void Game::Tile::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Game::Tile::SetIndexPosition(int x, int y)
{
	Transform* tr = GetComponent<Transform>();
	Vector2 pos;
	pos.x = x * TilemapRenderer::TileSize.x;
	pos.y = y * TilemapRenderer::TileSize.y;
	tr->SetPosition(pos);
}
