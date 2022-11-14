#include "Utils.h"

#include <iostream>

const double m_pi = 3.14159265358979323846;

namespace Utils {
	float GetAngle(Vector2 v1, Vector2 v2, Vector2 center) {
		float a = powf(center.x - v1.x, 2) + powf(center.y - v1.y, 2);
		float b = powf(center.x - v2.x, 2) + powf(center.y - v2.y, 2);
		float c = powf(v2.x - v1.x, 2) + powf(v2.y - v1.y, 2);
		return acosf((a + b - c) / sqrtf(4 * a * b));
	}

	float DegreesToRadians(float deg) {
		return static_cast<float>(deg * (m_pi / 180.0));
	}

	float RadiansToDegrees(float rad) {
		return static_cast<float>(rad * (180.0 / m_pi));
	}

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