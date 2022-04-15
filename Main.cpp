#define _WIN32_WINNT 0x0500
#include <tchar.h>
#include <Windows.h>

#include "GameState.h"
#include "Settings.h"

//Music by: Digital Math - Hop Up
//https://soundcloud.com/digital-math
//https://www.facebook.com/Digital.Math
//https://twitter.com/Digital_Math



void initialiseWindow()
{
	int windowPositionX = Settings::GameWindow::c_windowPositionX;
	int windowPositionY = Settings::GameWindow::c_windowPositionY;
	int windowWidth = Settings::GameWindow::c_windowWidth;
	int windowHeight = Settings::GameWindow::c_windowHeight;

	HWND window = GetConsoleWindow();
	MoveWindow(window, windowPositionX, windowPositionY, windowWidth, windowHeight, TRUE);
}

void initialiseFont()
{
	CONSOLE_FONT_INFOEX consoleFont = { 0 };
	consoleFont.cbSize = sizeof consoleFont;
	consoleFont.dwFontSize.X = 18;
	consoleFont.dwFontSize.Y = 18;
	wcscpy_s(consoleFont.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &consoleFont);
}

int main()
{
	//This bool will keep the game running
	bool hasGameExited = false;

	//initialise and set fonts and window
	initialiseFont();
	initialiseWindow();

	//Play music
	mciSendString(_T("play Audio/DigitalMath-HopUp.mp3 repeat"), NULL, 0, 0);

	//Get an instance of a game state
	GameState m_gameState;

	//While the game has not exited
	while (hasGameExited == false)
	{
		//Update and render the game state
		m_gameState.update();
		m_gameState.render();

		//Keep checking if the game has not exited
		hasGameExited = m_gameState.getHasExitedGame();

		//Sleep for 100 milliseconds
		Sleep(100);
	}

	return 0;
}