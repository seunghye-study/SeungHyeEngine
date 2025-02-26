#pragma once
#include "Entity.h"
#include "CommonInclude.h"
#include "GameObject.h"


namespace Game
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

	private:
		void FindDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void DeleteGameObjects(std::vector<GameObject*>& deleteObjs);
		void EraseGameObject();

	private:
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameobjectIter;
}


