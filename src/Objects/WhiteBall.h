#pragma once
#include "raylib.h"

struct Ball
{
	Vector2 pos;

	float width;
	float height;

	float radius;

	Color color;
};

Ball CreateBall();

void DrawBall(Ball mainBall);