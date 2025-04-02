#pragma once
#include "CommonInclude.h"
#include "BoxCollider2D.h"
#include "CircleCollider.h"

namespace Game
{
	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};
		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(Collider* left, Collider* right);

		static bool Intersect(Collider* left, Collider* right);

	private:
		// todo
		//static bool isBump(Vector2 leftPos, Vector2 rightPos, Vector2 leftSize, Vector2 rightSize);

	private:
		static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}


