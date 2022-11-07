#include "game.h"

#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;

namespace Pool {
	namespace Game {

		// Private
		void close();
		void draw();
		void update();
		void init();

		// --

		void close() {
			CloseWindow();
		}

		void draw() {
			BeginDrawing();
			ClearBackground(BLACK);

			EndDrawing();
		}

		void update() {
			while (!WindowShouldClose()) {
				// Update

				// Draw
				draw();
			}
		}

		void init() {
			InitWindow(screenWidth, screenHeight, "Algebra TP5");

		}

		// Public

		void runGame() {
			init();

			update();

			close();
		}
	}
}