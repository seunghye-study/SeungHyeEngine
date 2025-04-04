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
		SpaceBar,LButton, RButton, MButton,
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

		__forceinline static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down;  }
		__forceinline static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }
		__forceinline static GameMath::Vector2 GetMousePosition() { return mMousePosition; }


	private:
		static void CreateKey();
		static void UpdateKeys();
		static void UpdateKey(GameInput::Key& key);
		static bool IsKeyDown(eKeyCode keycode);
		static void UpdateKeyDown(GameInput::Key& key);
		static void UpdateKeyUp(GameInput::Key& key);
		static void GetMousePositionByWindow();
		static void ClearKeys();



	private:
		static std::vector<Key> mKeys;
		static GameMath::Vector2 mMousePosition;
	};
}


