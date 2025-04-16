#pragma once
#include "Scene.h"

namespace Game
{
	class MineScene : public Scene
	{
	public:

		MineScene();
		~MineScene();

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
