
#pragma once


namespace Game
{
	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Animal,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
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
		End,
	};

}