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
const int maxBalls = 6;
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
	mainBall = CreateBall();
	mainBall.pos.x = static_cast<float>(screenWidth / 6);
	mainBall.pos.y = static_cast<float>(screenHeight / 2);
	mainBall.mass = 130;
	mainBall.isActive = true;

	//Other Balls
	for (int i = 0; i < maxBalls; i++)
	{
		balls[i] = CreateBall();
	}

	balls[0].pos.x = static_cast<float>(screenWidth / 1.8);
	balls[0].pos.y = static_cast<float>(screenHeight / 2);
	balls[0].color = RED;
	balls[0].mass = 155;
	balls[0].isActive = true;
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

}

void Update()
{
	while (!WindowShouldClose())
	{
		Input::Manage(mainBall);

		Collision::BallCollision(maxBalls, mainBall, balls);


		for (int i = 0; i < maxBalls; i++)
		{
			if (balls[i].isActive)
			{
				UpdateBall(balls[i]);
			}
		}

		if (!mainBall.isActive)
		{
			mainBall.pos.x = static_cast<float>(screenWidth / 6);
			mainBall.pos.y = static_cast<float>(screenHeight / 2);
			//mainBall.isActive = true;
		}
		else
		{
			UpdateBall(mainBall);

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

	//White Ball
	DrawBall(mainBall);

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