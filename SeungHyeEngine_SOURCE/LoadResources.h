#pragma once
#include "Resources.h"
#include "Texture.h"

namespace Game
{
	void LoadResources()
	{
		// ī�޶� -> ũ������ -> ��ũ��Ʈ -> �̹��� �ڸ��� -> �ִϸ��̼� -> Ÿ�ϸ� -> �浹 -> UI -> ����
		Resources::Load<Texture>(L"Map", L"..\\Resources\\title\\Cloudy_Ocean.png");
		Resources::Load<Texture>(L"Farmer", L"..\\Resources\\animals\\CatAlpha.bmp");
	}
}