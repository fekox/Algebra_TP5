#pragma once
#include "raylib.h"
#include "Objects/Ball.h"

namespace Collision 
{
	void BallCollision(const int maxBalls, Ball balls[]);
	bool CircleCircleCollision(Vector2 aPos, float aRadius, Vector2 bPos, float bRadius);
}