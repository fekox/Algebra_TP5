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
	ball.pos.x += ball.velocity.x * GetFrameTime();
	ball.pos.y += ball.velocity.y * GetFrameTime();


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

void ShootBall(Ball& ball) 
{
	Vector2 forceOfHit = { (ball.pos.x - GetMousePosition().x) * 2,(ball.pos.y - GetMousePosition().y) * 2}; //La fuerza es el doble de la diferencia entre la posición del mouse y la pelota
	if (forceOfHit.x > 1280 || forceOfHit.y > 720)
	{
		forceOfHit = { 1280,720 };
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
	ball.acceleration = { -(ball.velocity.x * 0.8f + friction * GetFrameTime() + airFriction * GetFrameTime()), -(ball.velocity.y * 0.8f + friction * GetFrameTime() + airFriction * GetFrameTime()) };
	ball.velocity = { ball.velocity.x + ball.acceleration.x * GetFrameTime(), ball.velocity.y + ball.acceleration.y * GetFrameTime() };
}

void DrawBall(Ball mainBall)
{
	DrawCircle(static_cast<int>(mainBall.pos.x), static_cast<int>(mainBall.pos.y), mainBall.radius, mainBall.color);
}