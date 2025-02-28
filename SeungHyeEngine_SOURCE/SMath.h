#pragma once

namespace GameMath
{
#define PI 3.143592f

	struct Vector2
	{
		static Vector2 Rotate(Vector2 vector, float degree)
		{
			float radian = (degree / 180.f) * PI;
			vector.normalize();
			float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
			float y = sinf(radian) * vector.x - cosf(radian) * vector.y;
			return Vector2(x, y);
		}
		static float Dot(Vector2 v1, Vector2 v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}
		static float Cross(Vector2 v1, Vector2 v2)
		{
			return v1.x * v2.x - v1.y * v2.y;
		}

		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2()
			:x(0.0f), y(0.0f)
		{

		}
		Vector2(float _x, float _y)
			:x(_x), y(_y)
		{

		}

		Vector2 operator+(Vector2 target)
		{
			return Vector2(x + target.x, y + target.y);
		}

		Vector2 operator-(Vector2 target)
		{
			return Vector2(x - target.x, y - target.y);
		}

		Vector2 operator/(float target)
		{
			return Vector2(x /target, y / target);
		}
		Vector2 operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}
		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()
		{
			// ±Ê¿Ã 
			return sqrtf(x * x + y * y);
		}

		Vector2 normalize()
		{
			float len = length();
			x /= len;
			y /= len;
			return *this;
		}
	};
}

