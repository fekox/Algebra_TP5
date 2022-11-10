#include "InputManager.h"

namespace Input {
	void Manage(Ball& whiteBall) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
			GetMouseX() < GetScreenWidth() && GetMouseX() > 0 &&
			GetMouseY() < GetScreenHeight() && GetMouseY > 0) {
			ShootBall(whiteBall, GetMousePosition());
		}
	}
}