#pragma once

#include "Component.h"
#include "GameObject.h"
#include "Layer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"


namespace Game
{
	// 레이어 타입만
	template <typename T>
	static T* Instantiate(Game::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	// 레이어 타입+ 포지션
	template <typename T>
	static T* Instantiate(Game::eLayerType type, Game::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}