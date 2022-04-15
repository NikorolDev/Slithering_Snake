#ifndef SETTINGS_H
#define SETTINGS_H

namespace Settings
{
	namespace Characters
	{
		const char c_fruitCharacter				= 'F'; //The character that represents the fruit
		const char c_snakeCharacter				= 'O'; //The character that represents the snake
		const char c_pointerCharacter			= '>'; //The character that represents the pointer
	}

	namespace Colours
	{
		const int c_blackBox					= 0; //Black font with black background
		const int c_defaultConsoleColour		= 7; //White font with black background
		const int c_darkBlueBox					= 17; //Blue font with blue background
		const int c_darkGreenBox				= 34; //Dark green font with dark green background
		const int c_lightGreenBox				= 170; //Light green font with light green background
		const int c_cyanBox						= 187; //Cyan font with cyan background
		const int c_whiteBox					= 255; //White font with white background
	}

	namespace GameWindow
	{
		const int c_windowPositionX				= 0; //The position of the console window X
		const int c_windowPositionY				= 0; //The position of the console window Y
		const int c_windowWidth					= 1000; //The size of the window width
		const int c_windowHeight				= 600; //The size of the window height
	}

	namespace HUD
	{
		const int c_hudMaxWidth					= 19; //The max width of the HUD
		const int c_hudMaxHeight				= 30; //The max height of the HUD

		const int c_hudPositionX				= 30; //The position X of the HUD
		const int c_hudPositionY				= 0; //The position Y of the HUD

		const int c_hudTitlePositionX			= 31; //The position X of the game Title in the HUD
		const int c_hudTitlePositionY			= 2; //The position Y of the game Title in the HUD

		const int c_hudControlsHeadingPositionX = 35; //The position X of the controls heading in the HUD
		const int c_hudControlsHeadingPositionY = 6; //The position Y of the controls heading in the HUD

		const int c_hudControlUpPositionX		= 36; //The position X of the control up in the HUD
		const int c_hudControlUpPositionY		= 8; //The position Y of the control up in the HUD

		const int c_hudControlDownPositionX		= 36; //The position X of the controls down in the HUD
		const int c_hudControlDownPositionY		= 9; //The position Y of the controls down in the HUD

		const int c_hudControlLeftPositionX		= 36; //The position X of the controls left in the HUD
		const int c_hudControlLeftPositionY		= 10; //The position Y of the controls left in the HUD

		const int c_hudControlRightPositionX	= 36; //The position X of the controls right in the HUD
		const int c_hudControlRightPositionY	= 11; //The position Y of the controls right in the HUD

		const int c_hudControlExitPositionX		= 36; //The position X of the controls exit in the HUD
		const int c_hudControlExitPositionY		= 12; //The position Y of the controls exit in the HUD

		const int c_hudSnakePositionX			= 32; //The position X of the snake position in the HUD
		const int c_hudSnakePositionY			= 16; //The position Y of the snake position in the HUD

		const int c_hudScorePositionX			= 36; //The position X of the scores in the HUD
		const int c_hudScorePositionY			= 20; //The position Y of the scores in the HUD
	}

	namespace Map
	{
		const int c_mapMaxHeight				= 30; //The max height of the map
		const int c_mapMaxWidth					= 30; //The max width of the map
	}

	namespace Positions
	{
		const int c_middlePositionX				= 30; //The middle position X of the console window

		const int c_snakeSpawnPositionX			= 15; //The position X of the snake's spawn
		const int c_snakeSpawnPositionY			= 15; //The position Y of the snake's spawn

		const int c_consoleStartPositionX		= 0; //The position 0 on the X of the console 
		const int c_consoleStartPositionY		= 0; //The position 0 on the Y of the console 
	}

	namespace Title
	{
		const int c_titleWidth					= 38; //The title width of the game title
		const int c_titleHeight					= 13; //The title height of the game title
	}
}

#endif // !SETTINGS_H
