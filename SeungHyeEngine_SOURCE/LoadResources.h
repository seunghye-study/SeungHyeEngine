#pragma once
#include "Resources.h"
#include "Texture.h"

namespace Game
{
	void LoadResources()
	{
		// 카메라 -> 크기조정 -> 스크립트 -> 이미지 자르기 -> 애니메이션 -> 타일맵 -> 충돌 -> UI -> 사운드
		Resources::Load<Texture>(L"Map", L"..\\Resources\\title\\Cloudy_Ocean.png");
		Resources::Load<Texture>(L"Farmer", L"..\\Resources\\animals\\CatAlpha.bmp");
	}
}