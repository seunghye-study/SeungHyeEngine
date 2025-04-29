#pragma once

#include "CommonInclude.h"
#include "Component.h"
#include "Collider.h"

namespace Game
{
	class GameObject
	{
	public:
		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		friend void Destroy(GameObject* gameObject);

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		void Destroy(GameObject* gameObject);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

		eState GetState() { return mState; }
		void SetActive(bool power) 
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}

		eLayerType GetLayerType() { return mLayerType; }
		void SetLayerType(eLayerType layerType) { mLayerType = layerType; }
		
		bool IsActive() { return mState == eState::Active; }
		bool IsDead() { return mState == eState::Dead; }
		
		void InitializeTransform();
		void death() { mState = eState::Dead; }

	private:
		eState mState;
		Game::eLayerType mLayerType;
		std::vector<Component*> mComponents;
	};
}


