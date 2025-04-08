#pragma once
#include "Resources.h"
#include "Texture.h"

namespace Game
{
	void LoadResources()
	{
		// ī�޶� -> ũ������ -> ��ũ��Ʈ -> �̹��� �ڸ��� -> �ִϸ��̼� -> Ÿ�ϸ� -> �浹 -> UI -> ����
		//Resources::Load<Texture>(L"Map", L"..\\Resources\\title\\Cloudy_Ocean.png");
		// start map
		{
			Resources::Load<Texture>(L"FarmHouse", L"..\\Resources\\farmer_house\\Farmhouse.png");
		}
		
		//player
		{
			Resources::Load<Texture>(L"GoLeft", L"..\\Resources\\farmer\\Player.bmp");
			Resources::Load<Texture>(L"GoRight", L"..\\Resources\\farmer\\Player.bmp");
			Resources::Load<Texture>(L"GoUp", L"..\\Resources\\farmer\\Player.bmp");
			Resources::Load<Texture>(L"GoDown", L"..\\Resources\\farmer\\Player_Move_Down.bmp");
			Resources::Load<Texture>(L"Idle", L"..\\Resources\\farmer\\Player_Move_Down.bmp");
			// 9��°�� 1~12 ����
			Resources::Load<Texture>(L"GiveWaterFront", L"..\\Resources\\farmer\\Player.bmp");
		}
		// npc
		{
			Resources::Load<Texture>(L"Cat", L"..\\Resources\\animals\\CatAlpha.bmp");

		}

		
		// Tool Scene Resource
		{
			Resources::Load<Texture>(L"FarmSheet", L"..\\Resources\\maptool\\FarmSheet.bmp");
		}
	
	}
}