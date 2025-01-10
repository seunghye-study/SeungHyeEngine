#pragma once
#include "Entity.h"
#include "GameObject.h"

// scene �� game object�� ��ġ�ϰ�
// update - render ����

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

		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}