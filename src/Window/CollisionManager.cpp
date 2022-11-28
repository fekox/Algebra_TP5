#include <iostream>
#include "CollisionManager.h"
#include "Objects/Ball.h"
#include "Utils.h"

const int maxHoles = 6;
extern Utils::Circle Holes[maxHoles];
namespace Collision 
{
	using namespace std;


	void BallCollision(const int maxBalls, Ball mainBall, Ball balls[])
	{
<<<<<<< HEAD
		cout << mainBall.acceleration.x << endl;
		// Chequea la colicion de cada bola
=======

>>>>>>> 37d217c17ab4a875a5102a21ed2508a7e9fc58bf
		for (int i = 0; i < maxBalls; i++)
		{
			// La colision entre la bola blanca
			if (CircleCircleCollision(mainBall.pos, mainBall.radius, balls[i].pos, balls[i].radius))
			{
				float dis = sqrtf(powf(mainBall.pos.x - balls[i].pos.x, 2) + powf(mainBall.pos.y - balls[i].pos.y, 2));
				float overlap = 0.5f * (dis - mainBall.radius * 2);
				mainBall.pos = { mainBall.pos.x - overlap * (mainBall.pos.x - balls[i].pos.x) / dis, mainBall.pos.y - overlap * (mainBall.pos.y - balls[i].pos.y) / dis };

				balls[i].pos = { balls[i].pos.x + overlap * (mainBall.pos.x - balls[i].pos.x) / dis, balls[i].pos.y + overlap * (mainBall.pos.y - balls[i].pos.y) / dis };
				HandleBallBallBounce(balls[i], mainBall);
			}

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

				if (CircleCircleCollision(Holes[j].pos, Holes[j].Radius - 10, mainBall.pos, mainBall.radius))
				{
					mainBall.isActive = false;
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