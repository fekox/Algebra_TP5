#include "Table.h"
#include "raylib.h"
#include "Utils.h"


const int maxHoles = 6;

Rectangle Table;
Utils::Circle Holes[maxHoles];

void initTable()
{
	Table.width = 274 * 3;
	Table.height = 146 * 3;
	Table.x = 100;
	Table.y = GetScreenHeight() / 2 - Table.height / 2;

	for (int i = 0; i < maxHoles; i++)
	{
		Holes[i].Radius = 25;
		if (i < 3)
		{
			Holes[i].pos.x = Table.x + (i * Table.width / 2);
			Holes[i].pos.y = Table.y;
		}
		else
		{
			Holes[i].pos.x = Table.x + ((i - 3) * Table.width / 2);
			Holes[i].pos.y = Table.y + Table.height;
		}
	}
}

void DrawTable()
{
	DrawRectangle(static_cast<int>(Table.x), static_cast<int>(Table.y), static_cast<int>(Table.width), static_cast<int>(Table.height), DARKGREEN);
	for (int i = 0; i < maxHoles; i++)
	{
		DrawCircle(static_cast<int>(Holes[i].pos.x), static_cast<int>(Holes[i].pos.y), Holes[i].Radius, BROWN);
	}
}