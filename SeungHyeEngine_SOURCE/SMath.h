#pragma once
#include <cmath>

namespace GameMath
{
#define PI 3.141592f

	static float ConvertDegree(float radian)
	{
		return radian * (180 / PI);
	}

	struct Vector2
	{
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
		void operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}

		Vector2 operator-(Vector2 target)
		{
			return Vector2(x - target.x, y - target.y);
		}

		Vector2 operator-()
		{
			return Vector2(-x, -y);
		}

		Vector2 operator/(float target)
		{
			return Vector2(x / target, y / target);
		}
		Vector2 operator*(float value)
		{
			return Vector2(x * value, y * value);
		}

		Vector2 operator*(Vector2 v)
		{
			return Vector2(x * v.x, y * v.y);
		}

		bool operator==(Vector2 v)
		{
			return (x == v.x) && (y == v.y);
		}

		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2 normalize()
		{
			float len = length();
			x /= len;
			y /= len;
			return *this;
		}
		Vector2 Rotate(Vector2 vector, float degree);

		float Dot(Vector2& v1, Vector2& v2);

		float Cross(Vector2 v1, Vector2 v2);
		
	};
}

