#include <iostream>
#include <Windows.h>
#include "Helpers.h"

void moveToXYPosition(const Vector2& positionXY)
{
	HANDLE handleStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { (SHORT) positionXY.getPositionX(), (SHORT) positionXY.getPositionY() };

	SetConsoleCursorPosition(handleStdOut, position);
}

void drawCharacterInPosition(char character, const Vector2& positionXY)
{
	moveToXYPosition(positionXY);
	std::cout << character;
}

void colourCharacter(int colourID)
{
	HANDLE handleStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handleStdOut, colourID);
}
