#include "InputManager.h"

namespace Input {
	void Manage(Ball& whiteBall) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
			GetMouseX() < GetScreenWidth() && GetMouseX() > 0 &&
			GetMouseY() < GetScreenHeight() && GetMouseY() > 0)
		{
			ShootBall(whiteBall);
<<<<<<< HEAD
=======
			whiteBall.isMoving = true;
>>>>>>> 37d217c17ab4a875a5102a21ed2508a7e9fc58bf

		}
	}
}