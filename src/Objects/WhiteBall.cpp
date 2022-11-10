#include "Objects/WhiteBall.h"

Ball CreateBall()
{
	Ball mainBall;

	mainBall.pos.x = 0;
	mainBall.pos.y = 0;

	mainBall.width = 60;
	mainBall.height = 60;

	mainBall.radius = 20;

	mainBall.color = WHITE;

	return mainBall;
}

void DrawBall(Ball mainBall)
{
	DrawCircle(static_cast<int>(mainBall.pos.x), static_cast<int>(mainBall.pos.y), mainBall.radius, mainBall.color);
}