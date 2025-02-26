#pragma once

#include "CommonInclude.h"
#include "Component.h"
#include "Object.h"



namespace Game
{
	void Destroy(GameObject* gameObject);

	class GameObject
	{
	public:
		friend void Destroy(GameObject* obj);

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

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
			if (power)
				mState = eState::Active;
			else
				mState = eState::Paused;
		}
		void Death() { mState = eState::Dead; }
		bool IsActive() { return mState == eState::Active; }

	private:
		void InitializeTransform();
		bool IsDead() { return mState == eState::Dead; }
		std::vector<Component*> mComponents;
		eState mState;
	};
}


