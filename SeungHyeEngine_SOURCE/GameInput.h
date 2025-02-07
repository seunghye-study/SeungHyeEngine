#pragma once

#include "CommonInclude.h"

namespace Game
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		SpaceBar,
		End,
	};

	class GameInput
	{
	public:
		struct Key
		{
			eKeyState state;
			eKeyCode keyCode;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down;  }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }

		static void CreateKey();
		static void UpdateKeys();
		static void UpdateKey(GameInput::Key& key);
		static bool IsKeyDown(eKeyCode keycode);
		static void UpdateKeyDown(GameInput::Key& key);
		static void UpdateKeyUp(GameInput::Key& key);

	private:
		static std::vector<Key> mKeys;
	};
}


