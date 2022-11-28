#pragma once
#include "raylib.h"

struct Ball
{
	Vector2 pos;

	Vector2 direction;
	Vector2 acceleration;
	Vector2 velocity;

	float radius;
	float mass = 156;

	bool isActive;
	bool isMoving;
	bool onTable;

	Color color;
};

Ball CreateBall();

void HandleBallBallBounce(Ball& ball1, Ball& ball2);

void ShootBall(Ball& ball);

void UpdateBall(Ball& ball);

void ReduceSpeed(Ball& ball);

void DrawBall(Ball mainBall);