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
	InitWindow(screenWidth, screenHeight, "Algebra TP5");
	initTable();
	
	//White Ball
	mainBall = CreateBall();
	mainBall.pos.x = static_cast<float>(screenWidth / 6);
	mainBall.pos.y = static_cast<float>(screenHeight / 2);

	//Other Balls
	for (int i = 0; i < maxBalls; i++)
	{
		balls[i] = CreateBall();
	}

	balls[0].pos.x = static_cast<float>(screenWidth / 1.8);
	balls[0].pos.y = static_cast<float>(screenHeight / 2);
	balls[0].color = RED;
	//
	balls[1].pos.x = static_cast<float>(screenWidth / 1.65);
	balls[1].pos.y = static_cast<float>(screenHeight / 2.2);
	balls[1].color = BLUE;
	//
	balls[2].pos.x = static_cast<float>(screenWidth / 1.65);
	balls[2].pos.y = static_cast<float>(screenHeight / 1.8);
	balls[2].color = YELLOW;
	//
	balls[3].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[3].pos.y = static_cast<float>(screenHeight / 1.65);
	balls[3].color = ORANGE;
	//
	balls[4].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[4].pos.y = static_cast<float>(screenHeight / 2.5);
	balls[4].color = GREEN;
	//
	balls[5].pos.x = static_cast<float>(screenWidth / 1.50);
	balls[5].pos.y = static_cast<float>(screenHeight / 2);
	balls[5].color = PURPLE;

}

void Update()
{
	while (!WindowShouldClose())
	{
		Input::Manage(mainBall);

		Collision::BallCollision(maxBalls, mainBall, balls);

		UpdateBall(mainBall);

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
		DrawBall(balls[i]);
	}

	EndDrawing();
}