#include "game.h"

const int screenWidth = 800;
const int screenHeight = 600;

int main() {
	/*
	// Init
	InitWindow(screenWidth, screenHeight, "Algebra TP5");


	while (!WindowShouldClose()) {
		// Update

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();

	}
	// Close
	CloseWindow();
	*/
	Pool::Game::runGame();

	return 0;
}