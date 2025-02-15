#pragma once
#include "..\\SeungHyeEngine_SOURCE\GameObject.h"

namespace Game
{
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};

}

