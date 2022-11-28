#include "raylib.h"
#include "Window/PlayGame.h"
#include "Objects/Ball.h"
#include "Objects/Table.h"

#include "InputManager.h"
#include "CollisionManager.h"

//Window
int screenWidth = 1024;
int screenHeight = 768;

//WhiteBall
Ball mainBall;

//Other Balls
const int maxBalls = 7;
Ball balls[maxBalls];

void PlayGame()
{
	Init();
	Update();
}

void Init()
{
	//Window
	SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);
	InitWindow(screenWidth, screenHeight, "Algebra TP5");
	initTable();
	
	//White Ball

	//Other Balls
	for (int i = 0; i < maxBalls; i++)
	{
		balls[i] = CreateBall();
	}

	balls[6].pos.x = static_cast<float>(screenWidth / 1.8);
	balls[6].pos.y = static_cast<float>(screenHeight / 2);
	balls[6].color = RED;
	balls[6].mass = 155;
	balls[6].isActive = true;
	//
	balls[1].pos.x = static_cast<float>(screenWidth / 1.65);
	balls[1].pos.y = static_cast<float>(screenHeight / 2.2);
	balls[1].color = BLUE;
	balls[1].mass = 155;
	balls[1].isActive = true;
	//
	balls[2].pos.x = static_cast<float>(screenWidth / 1.65);
	balls[2].pos.y = static_cast<float>(screenHeight / 1.8);
	balls[2].color = YELLOW;
	balls[2].mass = 155;
	balls[2].isActive = true;
	//
	balls[3].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[3].pos.y = static_cast<float>(screenHeight / 1.65);
	balls[3].color = ORANGE;
	balls[3].mass = 155;
	balls[3].isActive = true;
	//
	balls[4].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[4].pos.y = static_cast<float>(screenHeight / 2.5);
	balls[4].color = GREEN;
	balls[4].mass = 155;
	balls[4].isActive = true;
	//
	balls[5].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[5].pos.y = static_cast<float>(screenHeight / 2);
	balls[5].color = PURPLE;
	balls[5].mass = 155;
	balls[5].isActive = true;

	balls[0] = CreateBall();
	balls[0].pos.x = static_cast<float>(screenWidth / 6);
	balls[0].pos.y = static_cast<float>(screenHeight / 2);
	balls[0].color = WHITE;
	balls[0].mass = 130;
	balls[0].isActive = true;

}

void Update()
{
	while (!WindowShouldClose())
	{
		Input::Manage(balls[0]);

		Collision::BallCollision(maxBalls, balls);

		for (int i = 0; i < maxBalls; i++)
		{
			if (balls[i].isActive)
			{
				UpdateBall(balls[i]);
			}
		}
		if (!balls[0].isActive)
		{
			balls[0].pos.x = static_cast<float>(screenWidth / 6);
			balls[0].pos.y = static_cast<float>(screenHeight / 2);
			balls[0].acceleration = { 0, 0 };
			balls[0].velocity = { 0, 0 };
			balls[0].isActive = true;
		}

		Draw();
	}

	CloseWindow();
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLANK);
	DrawTable();

	//Other Balls
	for (int i = 0; i < maxBalls; i++)
	{
		if (balls[i].isActive)
		{
			DrawBall(balls[i]);
		}
	}

	EndDrawing();
}