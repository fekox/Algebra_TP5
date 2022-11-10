#pragma once

#include "raylib.h"

namespace Utils {
	float GetDistance(Vector2 v1, Vector2 v2);
	float Modulo(Vector2 vec); // Modulo
	Vector2 GetTargetVector(Vector2 origin, Vector2 target); // Devuelve el vector entre 2 posiciones.
}
