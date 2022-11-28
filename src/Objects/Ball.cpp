#include "Objects/Ball.h"

#include "Utils.h"

#include <iostream>

using namespace std;

// Private

void Move(Ball& ball);
void HandleBounce(Ball& ball);

const float tableFriction = 0.2f;
const float gravity = 9.8f;
const float airDensity = 1.225f;
const float constantAirFriction = 0.000000667f;

const int radius = 18;
const float mass = 156;
const float friction = tableFriction * (mass * gravity);
const float airFriction = constantAirFriction * 0.5f * airDensity * (radius * radius) / 4;

// --

extern Rectangle Table;

void Move(Ball& ball) 
{

	ball.pos.x += ball.velocity.x * Utils::NormGetFrameTime();
	ball.pos.y += ball.velocity.y * Utils::NormGetFrameTime();

	ball.pos.x += ball.velocity.x * Utils::NormGetFrameTime();
	ball.pos.y += ball.velocity.y * Utils::NormGetFrameTime();

	if (fabs(ball.velocity.x * ball.velocity.x + ball.velocity.y * ball.velocity.y) < 1)
	{
		ball.velocity = { 0,0 };
		ball.acceleration = { 0,0 };
	}
}

void HandleBounce(Ball& ball) {
	if (ball.pos.x - ball.radius <= Table.x) 
	{
		ball.pos.x = ball.radius + Table.x + 1;
		ball.velocity.x = -ball.velocity.x / 2;
	}
	if (ball.pos.x + ball.radius >= Table.x + Table.width) 
	{
		ball.pos.x = Table.x + Table.width - ball.radius - 1;
		ball.velocity.x = -ball.velocity.x / 2;
	}
	if (ball.pos.y - ball.radius <= Table.y) 
	{
		ball.pos.y = ball.radius + Table.y + 1;
		ball.velocity.y = -ball.velocity.y / 2;
	}
	if (ball.pos.y + ball.radius >= Table.y + Table.height) 
	{
		ball.pos.y = Table.y + Table.height - ball.radius - 1;
		ball.velocity.y = -ball.velocity.y / 2;
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

	mainBall.velocity.x = 0;
	mainBall.velocity.y = 0;
	mainBall.radius = 20;
	mainBall.radius = 20;
	mainBall.mass = 155;

	mainBall.color = WHITE;

	return mainBall;
}

void HandleBallBallBounce(Ball& ball1, Ball& ball2) 
{
	float dis = sqrtf(powf(ball2.pos.x - ball1.pos.x, 2) + powf(ball2.pos.y - ball1.pos.y, 2));

	float normalX = (ball2.pos.x - ball1.pos.x) / dis;
	float normalY = (ball2.pos.y - ball1.pos.y) / dis;

	float tanX = -normalY;
	float tanY = normalX;

	float dotProductTangent1 = ball1.velocity.x * tanX + ball1.velocity.y * tanY;
	float dotProductTangent2 = ball2.velocity.x * tanX + ball2.velocity.y * tanY;

	float dotProductNormal1 = ball1.velocity.x * normalX + ball1.velocity.y * normalY;
	float dotProductNormal2 = ball2.velocity.x * normalX + ball2.velocity.y * normalY;

	float momentumConservation1 = (dotProductNormal1 / (ball1.mass * 2)) + dotProductNormal2;
	float momentumConservation2 = (dotProductNormal2 / (ball2.mass * 2)) + dotProductNormal1;

	ball1.velocity = { tanX * dotProductTangent1 + normalX * momentumConservation1, tanY * dotProductTangent1 + normalY * momentumConservation1 };
	ball2.velocity = { tanX * dotProductTangent2 + normalX * momentumConservation2, tanY * dotProductTangent2 + normalY * momentumConservation2 };
}

void ShootBall(Ball& ball) 
{
	//La fuerza es el doble de la diferencia entre la posición del mouse y la pelota
	Vector2 forceOfHit = { (ball.pos.x - GetMousePosition().x) * 2,(ball.pos.y - GetMousePosition().y) * 2}; 
	if (forceOfHit.x > GetScreenWidth() || forceOfHit.y > GetScreenHeight())
	{
		forceOfHit = { (float)GetScreenWidth(), (float)GetScreenHeight() };
	}
	ball.velocity = forceOfHit;
}

void UpdateBall(Ball& ball) 
{
	ReduceSpeed(ball);
	Move(ball);
	HandleBounce(ball);
}

void ReduceSpeed(Ball& ball)
{
	const float friction = 0.2f * (ball.mass * 9.8f);

	ball.acceleration = { -(ball.velocity.x + friction * Utils::NormGetFrameTime()), -(ball.velocity.y + friction * Utils::NormGetFrameTime()) };
	ball.velocity = { ball.velocity.x + ball.acceleration.x * Utils::NormGetFrameTime(), ball.velocity.y + ball.acceleration.y * Utils::NormGetFrameTime() };

	ball.acceleration = { -(ball.velocity.x * 0.8f + friction * GetFrameTime() + airFriction * GetFrameTime()), -(ball.velocity.y * 0.8f + friction * GetFrameTime() + airFriction * GetFrameTime()) };
	ball.velocity = { ball.velocity.x + ball.acceleration.x * GetFrameTime(), ball.velocity.y + ball.acceleration.y * GetFrameTime() };
}

void DrawBall(Ball mainBall)
{
	DrawCircle(static_cast<int>(mainBall.pos.x), static_cast<int>(mainBall.pos.y), mainBall.radius, mainBall.color);
}