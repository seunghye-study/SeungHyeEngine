#pragma once
#include "Script.h"


namespace Game
{
	class PlayerScript : public Script
	{
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


