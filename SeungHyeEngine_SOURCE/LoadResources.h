#pragma once
#include "Resources.h"
#include "Texture.h"

namespace Game
{
	void LoadResources()
	{
		// ī�޶� -> ũ������ -> ��ũ��Ʈ -> �̹��� �ڸ��� -> �ִϸ��̼� -> Ÿ�ϸ� -> �浹 -> UI -> ����
		Resources::Load<Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
	}
}