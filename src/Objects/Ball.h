#pragma once
#include "raylib.h"

struct Ball
{
	Vector2 pos;

	Vector2 acceleration;

	float radius;

	Color color;
};

Ball CreateBall();

void HandleBallBallBounce(Ball& ball1, Ball& ball2);

void ShootBall(Ball& ball, Vector2 target);

void UpdateBall(Ball& ball);

void DrawBall(Ball mainBall);