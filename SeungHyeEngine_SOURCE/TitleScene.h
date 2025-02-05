#pragma once

#include "Scene.h"
#include "GameObject.h"
#include "SpriteRenderer.h"

namespace Game
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}