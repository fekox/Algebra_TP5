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
const int maxBalls = 16;
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

	balls[0] = CreateBall();
	balls[0].pos.x = static_cast<float>(screenWidth / 6);
	balls[0].pos.y = static_cast<float>(screenHeight / 2);
	balls[0].color = WHITE;
	balls[0].mass = 130;
	balls[0].isActive = true;
	//
	balls[1].pos.x = static_cast<float>(screenWidth / 1.8);
	balls[1].pos.y = static_cast<float>(screenHeight / 2);
	balls[1].color = RED;
	balls[1].mass = 155;
	balls[1].isActive = true;
	//
	balls[2].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[2].pos.y = static_cast<float>(screenHeight / 2);
	balls[2].color = PURPLE;
	balls[2].mass = 155;
	balls[2].isActive = true;
	//
	balls[3].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[3].pos.y = static_cast<float>(screenHeight / 2.5);
	balls[3].color = GREEN;
	balls[3].mass = 155;
	balls[3].isActive = true;
	//
	balls[4].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[4].pos.y = static_cast<float>(screenHeight / 1.65);
	balls[4].color = ORANGE;
	balls[4].mass = 155;
	balls[4].isActive = true;
	//
	balls[5].pos.x = static_cast<float>(screenWidth / 1.65);
	balls[5].pos.y = static_cast<float>(screenHeight / 1.8);
	balls[5].color = YELLOW;
	balls[5].mass = 155;
	balls[5].isActive = true;
	//
	balls[6].pos.x = static_cast<float>(screenWidth / 1.65);
	balls[6].pos.y = static_cast<float>(screenHeight / 2.2);
	balls[6].color = BLUE;
	balls[6].mass = 155;
	balls[6].isActive = true;
	//
	balls[7].pos.x = static_cast<float>(screenWidth / 1.37);
	balls[7].pos.y = static_cast<float>(screenHeight / 2.25);
	balls[7].color = BROWN;
	balls[7].mass = 155;
	balls[7].isActive = true;
	//
	balls[8].pos.x = static_cast<float>(screenWidth / 1.37);
	balls[8].pos.y = static_cast<float>(screenHeight / 2.9);
	balls[8].color = BLACK;
	balls[8].mass = 155;
	balls[8].isActive = true;
	//
	balls[9].pos.x = static_cast<float>(screenWidth / 1.37);
	balls[9].pos.y = static_cast<float>(screenHeight / 1.8);
	balls[9].color = MAGENTA;
	balls[9].mass = 155;
	balls[9].isActive = true;
	//
	balls[10].pos.x = static_cast<float>(screenWidth / 1.37);
	balls[10].pos.y = static_cast<float>(screenHeight / 1.5);
	balls[10].color = DARKBLUE;
	balls[10].mass = 155;
	balls[10].isActive = true;
	//
	balls[11].pos.x = static_cast<float>(screenWidth / 1.27);
	balls[11].pos.y = static_cast<float>(screenHeight / 1.63);
	balls[11].color = MAROON;
	balls[11].mass = 155;
	balls[11].isActive = true;
	//
	balls[12].pos.x = static_cast<float>(screenWidth / 1.27);
	balls[12].pos.y = static_cast<float>(screenHeight / 1.61);
	balls[12].color = LIME;
	balls[12].mass = 155;
	balls[12].isActive = true;
	//
	balls[13].pos.x = static_cast<float>(screenWidth / 1.27);
	balls[13].pos.y = static_cast<float>(screenHeight / 2);
	balls[13].color = SKYBLUE;
	balls[13].mass = 155;
	balls[13].isActive = true;
	//
	balls[14].pos.x = static_cast<float>(screenWidth / 1.27);
	balls[14].pos.y = static_cast<float>(screenHeight / 2.5);
	balls[14].color = PINK;
	balls[14].mass = 155;
	balls[14].isActive = true;
	//
	balls[15].pos.x = static_cast<float>(screenWidth / 1.27);
	balls[15].pos.y = static_cast<float>(screenHeight / 3.4);
	balls[15].color = BEIGE;
	balls[15].mass = 155;
	balls[15].isActive = true;
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