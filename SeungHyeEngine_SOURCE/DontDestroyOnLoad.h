#pragma once

#include "Scene.h"


namespace Game
{
	class DontDestroyOnLoad : public Scene
	{

	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

	};
}


