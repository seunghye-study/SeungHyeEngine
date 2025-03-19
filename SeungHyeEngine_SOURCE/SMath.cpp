#include "SMath.h"

namespace GameMath
{
	Vector2 Vector2::One = Vector2(1.0f, 1.0f);
	Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
	Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
	Vector2 Vector2::Left = Vector2(-1.0f, 0.0f);
	Vector2 Vector2::Up = Vector2(0.0f, -1.0f);
	Vector2 Vector2::Down = Vector2(0.0f, 1.0f);

	Vector2 Vector2::Rotate(Vector2 vector, float degree)
	{
		float radian = (degree / 180.0f) * PI;
		vector.normalize();
		float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
		float y = sinf(radian) * vector.x + cosf(radian) * vector.y;

		return Vector2(x, y);
	}

	float Vector2::Dot(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float Vector2::Cross(Vector2 v1, Vector2 v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}
}
