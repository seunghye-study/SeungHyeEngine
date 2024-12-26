#include "GameInput.h"

namespace Game
{
	std::vector<GameInput::Key> GameInput::mKeys = {};

	int ASCII[(UINT)EKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
	};
}

void Game::GameInput::Initialize()
{
	CreateKey();
}

void Game::GameInput::CreateKey()
{
	for (size_t i = 0; i < (UINT)EKeyCode::End; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.state = EKeyState::None;
		key.keyCode = (EKeyCode)i;

		mKeys.push_back(key);
	}
}

void Game::GameInput::Update()
{
	UpdateKeys();
}

void Game::GameInput::UpdateKeys()
{
	std::for_each(mKeys.begin(), mKeys.end(),
		[](Key& key) -> void
		{
			UpdateKey(key);
		});
}

void Game::GameInput::UpdateKey(GameInput::Key& key)
{
	if (IsKeyDown(key.keyCode))
	{
		UpdateKeyDown(key);
	}
	else
	{
		UpdateKeyUp(key);
	}
}

bool Game::GameInput::IsKeyDown(EKeyCode keycode)
{
	return GetAsyncKeyState(ASCII[(UINT)keycode]) & 0x8000;
}

void Game::GameInput::UpdateKeyDown(GameInput::Key& key)
{
	if (key.bPressed)
	{
		key.state = EKeyState::Pressed;
	}
	else
	{
		key.state = EKeyState::Down;
	}
	key.bPressed = true;
}

void Game::GameInput::UpdateKeyUp(GameInput::Key& key)
{
	if (key.bPressed)
	{
		key.state = EKeyState::Up;
	}
	else
	{
		key.state = EKeyState::None;
	}
	key.bPressed = false;
}



