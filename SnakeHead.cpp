#include <conio.h>

#include "Helpers.h"
#include "Settings.h"
#include "SnakeHead.h"

SnakeHead::SnakeHead()
{
	//This is the default constructor so set the values to 0 and character to blank
	initialise(' ',getPositionXYReadOnly());
}

SnakeHead::SnakeHead(char snakeHeadCharacter, const Vector2& startingPositionXY)
{
	//This will set the values passed through the parameter
	initialise(snakeHeadCharacter, startingPositionXY);
}

SnakeHead::~SnakeHead()
{
}

void SnakeHead::update()
{
	//Unrender the snake head every update call, then check for key input and move the snake
	unrender();
	inputManager();
	movement();
}

void SnakeHead::render()
{
	//Colour snake head and draw the snake head character
	colourCharacter(Settings::Colours::c_lightGreenBox);
	drawCharacterInPosition(m_snakeHeadCharacter, getPositionXYReadOnly());
}

void SnakeHead::unrender()
{	
	//Draw blank character to unrender the snake head
	drawCharacterInPosition(' ', getPositionXYReadOnly());
}

void SnakeHead::initialise(char snakeHeadCharacter, const Vector2& startingPositionXY)
{
	//Also on initialise it will reset the values when going back to the game mode
	m_hasExitedGameMode		= false;
	
	//Set these values from parameters passed through the constructor
	m_snakeHeadCharacter	= snakeHeadCharacter;
	m_currentSnakePositionX = startingPositionXY.getPositionX();
	m_currentSnakePositionY = startingPositionXY.getPositionY();

	//This will set the enum to do nothing as it's not part of the case in the input manager
	m_snakeControls			= EnumSnakeControls::NumberOfControls; 

	//Set the character and the position of the snake head to be at the spawn point
	setCharacter(m_snakeHeadCharacter);
	setPositionXY(m_currentSnakePositionX, m_currentSnakePositionY);
}

void SnakeHead::inputManager()
{
	//Check if a key on the keyboard has been pressed
	if (_kbhit())
	{
		//Set the key that was pressed
		char keyID = _getch();

		//Based on the key pressed it will set the direction of the snake head or exit the game mode
		switch (keyID)
		{
			case 'w': //Go up
			{
				m_snakeControls = EnumSnakeControls::Up;
				break;
			}

			case 's': //Go down
			{
				m_snakeControls = EnumSnakeControls::Down;
				break;
			}

			case 'a': //Go Left
			{
				m_snakeControls = EnumSnakeControls::Left;
				break;
			}

			case 'd': //Go Right
			{
				m_snakeControls = EnumSnakeControls::Right;
				break;
			}

			case 'x': //Exit the game mode
			{
				m_snakeControls = EnumSnakeControls::Quit;
				m_hasExitedGameMode = true;
				break;
			}
		}
	}
}

void SnakeHead::movement()
{
	//Check which direction the snake is meant to go
	//We don't need to set quit as it is not a movement and it has been set what it will do
	switch (m_snakeControls)
	{
		case EnumSnakeControls::Up: //Move up
		{
			m_currentSnakePositionY--;
			break;
		}

		case EnumSnakeControls::Down: //Move Down
		{
			m_currentSnakePositionY++;
			break;
		}

		case EnumSnakeControls::Left: //Move Left
		{
			m_currentSnakePositionX--;
			break;
		}

		case EnumSnakeControls::Right: //Move Right
		{
			m_currentSnakePositionX++;
			break;
		}
	}

	//Set the position of the snake head so it can be used by other objects, such as the snake tail
	setPositionXY(m_currentSnakePositionX, m_currentSnakePositionY);
}

bool SnakeHead::getHasExitedGameMode() { return m_hasExitedGameMode; }