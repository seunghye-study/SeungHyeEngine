#include "Destroy.h"
#include "GameObject.h"


void Game::Destroy(GameObject* obj)
{
	obj->death();
}
