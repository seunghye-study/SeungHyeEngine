#pragma once
#include "Resources.h"
#include "Texture.h"

namespace Game
{
	void LoadResources()
	{
		// 카메라 -> 크기조정 -> 스크립트 -> 이미지 자르기 -> 애니메이션 -> 타일맵 -> 충돌 -> UI -> 사운드
		//Resources::Load<Texture>(L"Map", L"..\\Resources\\title\\Cloudy_Ocean.png");
		// start map
		{
			Resources::Load<Texture>(L"FarmHouse", L"..\\Resources\\farmer_house\\Standard_Farm_Bmp.bmp");
		}
		
		Resources::Load<Texture>(L"GoLeft", L"..\\Resources\\farmer\\Player.bmp");
		Resources::Load<Texture>(L"GoRight", L"..\\Resources\\farmer\\Player.bmp");
		Resources::Load<Texture>(L"GoUp", L"..\\Resources\\farmer\\Player.bmp");
		Resources::Load<Texture>(L"GoDown", L"..\\Resources\\farmer\\Player_Move_Down.bmp");
		Resources::Load<Texture>(L"Idle", L"..\\Resources\\farmer\\Player_Move_Down.bmp");
		
		Resources::Load<Texture>(L"Cat", L"..\\Resources\\animals\\CatAlpha.bmp");
		
		
	
	}
}