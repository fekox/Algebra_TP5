#include <iostream>
#include "CollisionManager.h"
#include "Objects/Ball.h"

namespace Collision 
{
	using namespace std;


	void BallCollision(const int maxBalls, Ball mainBall, Ball balls[])
	{

		for (int i = 0; i < maxBalls; i++)
		{
			if (CircleCircleCollision(mainBall.pos, mainBall.radius, balls[i].pos, balls[i].radius))
			{
				cout << "Colision between Main Ball and ball " << i << "!" << endl;
				HandleBallBallBounce(mainBall, balls[i]);
			}
		}

		for (int i = 0; i < maxBalls; i++)
		{
			for (int j = 0; j < maxBalls; j++)
			{

				if (CircleCircleCollision(balls[i].pos, balls[i].radius, balls[j].pos, balls[j].radius) && i != j)
				{
					cout << "Colision between ball " << i << " and ball " << j << "!" << endl;
				}
			}
		}
	}

	bool CircleCircleCollision(Vector2 aPos, float aRadius, Vector2 bPos, float bRadius)
	{
		float distX = aPos.x - bPos.x;
		float distY = aPos.y - bPos.y;
		float dist = sqrtf((distX * distX) + (distY * distY));

		return (dist <= (aRadius + bRadius));
	}
}