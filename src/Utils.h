#pragma once

#include "raylib.h"

namespace Utils {

	struct Circle
	{
		Vector2 pos;
		float Radius;
	};

	float GetAngle(Vector2 v1, Vector2 v2, Vector2 center);
	float DegreesToRadians(float deg);
	float RadiansToDegrees(float rad);
	float GetDistance(Vector2 v1, Vector2 v2);
	float Modulo(Vector2 vec); // Modulo
	Vector2 GetTargetVector(Vector2 origin, Vector2 target); // Devuelve el vector entre 2 posiciones.
}
