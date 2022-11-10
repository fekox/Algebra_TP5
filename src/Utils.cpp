#include "Utils.h"

#include <iostream>

namespace Utils {
	float GetDistance(Vector2 v1, Vector2 v2)
	{
		float distX = v1.x - v2.x;
		float distY = v1.y - v2.y;
		return sqrt((distX * distX) + (distY * distY));
	}

	float Modulo(Vector2 vec) {
		return sqrtf((vec.x * vec.x) + (vec.y * vec.y));
	}

	Vector2 GetTargetVector(Vector2 origin, Vector2 target) {
		Vector2 targetVector = {
			(target.x - origin.x),
			(target.y - origin.y)
		};
		return targetVector;
	}
}