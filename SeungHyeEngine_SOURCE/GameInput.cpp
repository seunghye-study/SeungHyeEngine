#include "GameInput.h"
#include "Application.h"

extern Game::Application application;

namespace Game
{
	std::vector<GameInput::Key> GameInput::mKeys = {};
	GameMath::Vector2 GameInput::mMousePosition = Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE,
		VK_LBUTTON, VK_RBUTTON, VK_MBUTTON
	};
}

void Game::GameInput::Initialize()
{
	
	CreateKey();
}

void Game::GameInput::CreateKey()
{
	for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.state = eKeyState::None;
		key.keyCode = (eKeyCode)i;

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
	if (GetFocus())
	{
		if (IsKeyDown(key.keyCode))
			UpdateKeyDown(key);
		else
			UpdateKeyUp(key);

		GetMousePositionByWindow();
	}
	else
	{
		ClearKeys();
	}
}

bool Game::GameInput::IsKeyDown(eKeyCode keycode)
{
	return GetAsyncKeyState(ASCII[(UINT)keycode]) & 0x8000;
}

void Game::GameInput::UpdateKeyDown(GameInput::Key& key)
{
	if (key.bPressed)
	{
		key.state = eKeyState::Pressed;
	}
	else
	{
		key.state = eKeyState::Down;
	}
	key.bPressed = true;
}

void Game::GameInput::UpdateKeyUp(GameInput::Key& key)
{
	if (key.bPressed)
	{
		key.state = eKeyState::Up;
	}
	else
	{
		key.state = eKeyState::None;
	}
	key.bPressed = false;
}

void Game::GameInput::GetMousePositionByWindow()
{
	POINT mousePos = {};
	GetCursorPos(&mousePos);
	ScreenToClient(application.GetHWND(), &mousePos);

	mMousePosition.x = mousePos.x;
	mMousePosition.y = mousePos.y;
}

void Game::GameInput::ClearKeys()
{
	for (Key& key : mKeys)
	{
		if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
			key.state = eKeyState::Up;
		else if (key.state == eKeyState::Up)
			key.state = eKeyState::None;

		key.bPressed = false;
	}
}



