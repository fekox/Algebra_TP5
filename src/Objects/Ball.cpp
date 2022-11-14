#include "Objects/Ball.h"

#include "Utils.h"

#include <iostream>

using namespace std;

// Private

void Move(Ball& ball);
void HandleBounce(Ball& ball);

// --

void Move(Ball& ball) {
	ball.pos.x += (ball.acceleration.x * GetFrameTime()) * 200.0f;
	ball.pos.y += (ball.acceleration.y * GetFrameTime()) * 200.0f;
}

void HandleBounce(Ball& ball) {
	if (ball.pos.x - ball.radius <= 0) {
		ball.pos.x = ball.radius + 1;
		ball.acceleration.x = -ball.acceleration.x;
	}
	if (ball.pos.x + ball.radius >= GetScreenWidth()) {
		ball.pos.x = GetScreenWidth() - ball.radius - 1;
		ball.acceleration.x = -ball.acceleration.x;
	}
	if (ball.pos.y - ball.radius <= 0) {
		ball.pos.y = ball.radius + 1;
		ball.acceleration.y = -ball.acceleration.y;
	}
	if (ball.pos.y + ball.radius >= GetScreenHeight()) {
		ball.pos.y = GetScreenHeight() - ball.radius - 1;
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

	mainBall.color = WHITE;

	return mainBall;
}

void ShootBall(Ball& ball, Vector2 target) {
	Vector2 vectorDir = Utils::GetTargetVector(ball.pos, target);
	Vector2 normalizedDir;
	normalizedDir.x = (vectorDir.x / Utils::Modulo(vectorDir));
	normalizedDir.y = (vectorDir.y / Utils::Modulo(vectorDir));

	ball.acceleration.x += (normalizedDir.x * GetFrameTime()) * Utils::GetDistance(ball.pos, target);
	ball.acceleration.y += (normalizedDir.y * GetFrameTime()) * Utils::GetDistance(ball.pos, target);
	cout << "shot\n";
}

void UpdateBall(Ball& ball) {
	Move(ball);
	HandleBounce(ball);
}

void DrawBall(Ball mainBall)
{
	DrawCircle(static_cast<int>(mainBall.pos.x), static_cast<int>(mainBall.pos.y), mainBall.radius, mainBall.color);
}