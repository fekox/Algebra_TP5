#include "Objects/Ball.h"

#include "Utils.h"

#include <iostream>

using namespace std;

// Private

void Move(Ball& ball);
void HandleBounce(Ball& ball);

// --

extern Rectangle Table;

void Move(Ball& ball) {
	ball.pos.x += (ball.acceleration.x * GetFrameTime()) * 200.0f;
	ball.pos.y += (ball.acceleration.y * GetFrameTime()) * 200.0f;
}

void HandleBounce(Ball& ball) {
	if (ball.pos.x - ball.radius <= Table.x) {
		ball.pos.x = ball.radius + Table.x + 1;
		ball.acceleration.x = -ball.acceleration.x;
	}
	if (ball.pos.x + ball.radius >= Table.x + Table.width) {
		ball.pos.x = Table.x + Table.width - ball.radius - 1;
		ball.acceleration.x = -ball.acceleration.x;
	}
	if (ball.pos.y - ball.radius <= Table.y) {
		ball.pos.y = ball.radius + Table.y + 1;
		ball.acceleration.y = -ball.acceleration.y;
	}
	if (ball.pos.y + ball.radius >= Table.y + Table.height) {
		ball.pos.y = Table.y + Table.height - ball.radius - 1;
		ball.acceleration.y = -ball.acceleration.y;
	}
}

// Public

Ball CreateBall()
{
	Ball mainBall;

	mainBall.pos.x = 0;
	mainBall.pos.y = 0;

	mainBall.acceleration.x = 0;
	mainBall.acceleration.y = 0;

	mainBall.radius = 20;

	mainBall.isMoving = false;

	mainBall.color = WHITE;

	return mainBall;
}

void HandleBallBallBounce(Ball& ball1, Ball& ball2) {
	Vector2 targetVector = Utils::GetTargetVector(ball1.pos, ball2.pos);
	Vector2 directionVector = ball1.acceleration;
	float angle = Utils::RadiansToDegrees(Utils::GetAngle(targetVector, directionVector, ball2.pos));
	cout << "Collision angle: " << angle << endl;
}

void ShootBall(Ball& ball, Vector2 target) 
{
	Vector2 vectorDir = Utils::GetTargetVector(ball.pos, target);
	Vector2 normalizedDir;
	normalizedDir.x = (vectorDir.x / Utils::Modulo(vectorDir));
	normalizedDir.y = (vectorDir.y / Utils::Modulo(vectorDir));

	ball.acceleration.x += (normalizedDir.x * GetFrameTime()) * Utils::GetDistance(ball.pos, target);
	ball.acceleration.y += (normalizedDir.y * GetFrameTime()) * Utils::GetDistance(ball.pos, target);
	cout << "shot\n";

	if (ball.acceleration.x > 6.0f)
	{
		ball.acceleration.x = 6.0f;
	}

	if (ball.acceleration.y > 6.0f)
	{
		ball.acceleration.y = 6.0f;
	}

	if (ball.acceleration.x < -6.0f)
	{
		ball.acceleration.x = -6.0f;
	}

	if (ball.acceleration.y < -6.0f)
	{
		ball.acceleration.y = -6.0f;
	}
}

void UpdateBall(Ball& ball) 
{
	Move(ball);
	HandleBounce(ball);
	ReduceSpeed(ball);
}

void ReduceSpeed(Ball& ball)
{
	float friction = .97f;

	if (ball.isMoving == true)
	{
		if (ball.acceleration.x > 0)
		{
			ball.acceleration.x *= friction;

			if (ball.acceleration.x == 0)
			{
				ball.acceleration.x = 0;
				ball.isMoving = false;
			}
		}

		if (ball.acceleration.y > 0)
		{
			ball.acceleration.y *= friction;

			if (ball.acceleration.y == 0)
			{
				ball.acceleration.y = 0;
				ball.isMoving = false;
			}
		}

		if (ball.acceleration.x < 0)
		{
			ball.acceleration.x *= friction;

			if (ball.acceleration.x == 0)
			{
				ball.acceleration.x = 0;
				ball.isMoving = false;
			}
		}

		if (ball.acceleration.y < 0)
		{
			ball.acceleration.y *= friction;

			if (ball.acceleration.y == 0)
			{
				ball.acceleration.y = 0;
				ball.isMoving = false;
			}
		}
	}

	cout << "Ball aceleration X: " << ball.acceleration.x << endl;
	cout << "Ball aceleration Y: " << ball.acceleration.y << endl;
}

void DrawBall(Ball mainBall)
{
	DrawCircle(static_cast<int>(mainBall.pos.x), static_cast<int>(mainBall.pos.y), mainBall.radius, mainBall.color);
}