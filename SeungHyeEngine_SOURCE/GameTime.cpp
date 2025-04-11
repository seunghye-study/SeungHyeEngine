#include "GameTime.h"
#include "GameInput.h"


namespace Game
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		QueryPerformanceFrequency(&CpuFrequency);
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float diffrenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = diffrenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		{
			//print time
			static float time = 0.0f;
			time += DeltaTimeValue;

			float fps = 1.0f / DeltaTimeValue;

			//wchar_t str[50] = L"";
			//swprintf_s(str, 50, L"Time : %d", (int)fps);
			//int len = wcsnlen_s(str, 50);

			//TextOut(hdc, 0, 0, str, len);
		}
		
		{
			//print pos
			GameMath::Vector2 mousePos = GameInput::GetMousePosition(); // 마우스 위치
			wchar_t str[100] = {};
			swprintf_s(str, 100, L"Mouse Position: (%.0f, %.0f)", mousePos.x, mousePos.y);

			TextOut(hdc, 10, 10, str, wcslen(str)); // 좌측 상단에 출력
		}
	}
}
