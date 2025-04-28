
#pragma once


namespace Game
{
	enum class eLayerType
	{
		None,
		BackGround,
		Tile,
		Player,
		Animal,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		Animator,
		Collider,
		Rigidbody,
		End,
	};

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};

}