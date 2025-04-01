#include "Script.h"
#include "Collider.h"


Game::Script::Script() : Component(eComponentType::Script)
{
}

Game::Script::~Script()
{
}

void Game::Script::Initialize()
{
}

void Game::Script::Update()
{
}

void Game::Script::LateUpdate()
{
}

void Game::Script::Render(HDC hdc)
{
}

void Game::Script::OnCollisionEnter(Collider* other)
{
}

void Game::Script::OnCollisionStay(Collider* other)
{
}

void Game::Script::OnCollisionExit(Collider* other)
{
}
