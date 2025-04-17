#pragma once
#include "Scene.h"

namespace Game
{
	class VillageScene : public Scene
	{
	public:

		VillageScene();
		~VillageScene();

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
