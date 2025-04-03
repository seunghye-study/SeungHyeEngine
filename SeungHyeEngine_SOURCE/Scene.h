#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "Layer.h"

namespace Game
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const eLayerType type);
		Layer* GetLayer(const eLayerType type) { return mLayers[(UINT)type]; }
		void EraseGameObject(GameObject* gameObj);

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> mLayers;

	};
}