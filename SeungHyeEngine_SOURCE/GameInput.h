#pragma once

#include "CommonInclude.h"

namespace Game
{
	enum class EKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class EKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};

	class GameInput
	{
	public:
		struct Key
		{
			EKeyState state;
			EKeyCode keyCode;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(EKeyCode code) { return mKeys[(UINT)code].state == EKeyState::Down;  }
		static bool GetKeyUp(EKeyCode code) { return mKeys[(UINT)code].state == EKeyState::Up; }
		static bool GetKey(EKeyCode code) { return mKeys[(UINT)code].state == EKeyState::Pressed; }

		static void CreateKey();
		static void UpdateKeys();
		static void UpdateKey(GameInput::Key& key);
		static bool IsKeyDown(EKeyCode keycode);
		static void UpdateKeyDown(GameInput::Key& key);
		static void UpdateKeyUp(GameInput::Key& key);

	private:
		static std::vector<Key> mKeys;
	};
}


