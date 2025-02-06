#pragma once
#include "Resources.h"
#include "Texture.h"

namespace Game
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"BG", L"E:\\AR50\\YamYam_Engine\\Resources\\CloudOcean.png");
	}
}