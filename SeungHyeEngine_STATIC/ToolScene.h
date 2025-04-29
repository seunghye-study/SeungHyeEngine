#pragma once

#include "Scene.h"
#include "Tile.h"

namespace Game
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

		void Save();
		void Load();

		void RenderGreed(HDC hdc);
		void CreateTileObject();
		
		static LRESULT CALLBACK TileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		std::vector<Tile*> mTiles;
	};
}


