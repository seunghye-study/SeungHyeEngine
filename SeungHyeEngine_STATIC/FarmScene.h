#pragma once
#include "Scene.h"

namespace Game
{
	class FarmScene : public Scene
	{
	public:

		FarmScene();
		~FarmScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

	private:
		class GamePlayer* mPlayer;
	};
}


