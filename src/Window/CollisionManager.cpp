#include <iostream>
#include "CollisionManager.h"
#include "Objects/Ball.h"
#include "Utils.h"

const int maxHoles = 6;
extern Utils::Circle Holes[maxHoles];
namespace Collision 
{
	using namespace std;


	void BallCollision(const int maxBalls, Ball balls[])
	{
		// Chequea la colicion de cada bola
		for (int i = 0; i < maxBalls; i++)
		{
			// La colicion entre las misma bolas
			for (int j = 0; j < maxBalls; j++)
			{
				if (CircleCircleCollision(balls[i].pos, balls[i].radius, balls[j].pos, balls[j].radius) && i != j)
				{
					float dis = sqrtf(powf(balls[i].pos.x - balls[j].pos.x, 2) + powf(balls[i].pos.y - balls[j].pos.y, 2));
					float overlap = 0.5f * (dis - balls[i].radius * 2);
					balls[i].pos = { balls[i].pos.x - overlap * (balls[i].pos.x - balls[j].pos.x) / dis, balls[i].pos.y - overlap * (balls[i].pos.y - balls[j].pos.y) / dis };

					balls[j].pos = { balls[j].pos.x + overlap * (balls[i].pos.x - balls[j].pos.x) / dis, balls[j].pos.y + overlap * (balls[i].pos.y - balls[j].pos.y) / dis };

					HandleBallBallBounce(balls[i], balls[j]);
				}
			}

			// La colision con los agujeros de la mesa
			for (int j = 0; j < maxHoles; j++)
			{
				if (CircleCircleCollision(Holes[j].pos, Holes[j].Radius - 10, balls[i].pos, balls[i].radius))
				{
					balls[i].isActive = false;
				}
			}
		}
	}

	bool CircleCircleCollision(Vector2 aPos, float aRadius, Vector2 bPos, float bRadius)
	{
		float disX = aPos.x - bPos.x;
		float disY = aPos.y - bPos.y;
		float dis = sqrtf((disX * disX) + (disY * disY));

		return (dis <= (aRadius + bRadius));
	}
}