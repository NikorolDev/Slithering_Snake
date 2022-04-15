#include "Helpers.h"
#include "Settings.h"
#include "Snake.h"

Snake::Snake()
{
	//This is the default constructor so set the values to 0
	initialise(' ', 0, 0, 0);
}

Snake::Snake(char snakeCharacter, int startingSnakePositionX, int startingSnakePositionY, int numberOfTailSegments)
{
	//This will set the values passed through the parameter
	initialise(snakeCharacter, startingSnakePositionX, startingSnakePositionY, numberOfTailSegments);
}

Snake::~Snake()
{

}

void Snake::update()
{
	//Update the snake tail using the parameter of the snake head's current position and number of tail segments
	m_snakeTail.update(m_numberOfTailSegments, m_snakeHead.getPositionXYReadOnly());
	
	//Update the snake head and set the position of the snake body using the snake head
	m_snakeHead.update();
	setPositionXY(m_snakeHead.getPositionX(), m_snakeHead.getPositionY());

	//Check if the game is still playing
	checkGameIsPlaying();
}

void Snake::render()
{
	//render the snake head and tail
	m_snakeHead.render();
	m_snakeTail.render();
}

void Snake::initialise(char snakeCharacter, int startingSnakePositionX, int startingSnakePositionY, int numberOfTailSegments)
{
	//Initialise these values
	m_hasGameModeExited = false;

	//Set these variables using the values passed through
	m_snakeCharacter				= snakeCharacter;
	m_snakePositionX				= startingSnakePositionX;
	m_snakePositionY				= startingSnakePositionY;
	m_numberOfTailSegments			= numberOfTailSegments;

	//Set the position of snake body
	setPositionXY(m_snakePositionX, m_snakePositionY);

	//Initialise the snake head and snake tail using these constructors
	m_snakeHead = SnakeHead(m_snakeCharacter, getPositionXYReadOnly());
	m_snakeTail = SnakeTail(m_snakeCharacter, getPositionXYReadOnly(), m_numberOfTailSegments);
}

void Snake::checkGameIsPlaying()
{
	//If the player not pressed to exit or if the snake has collided with itself
	if (m_snakeHead.getHasExitedGameMode() == true || m_snakeTail.getHasSnakeHeadCollided() == true)
	{
		//The game is not playing and will exit the game mode
		m_hasGameModeExited = true;
	}
}

void Snake::setNumberOfTailSegments(int numberOfTailSegments)
{
	//Set the number of tail segments from the passed parameter
	m_numberOfTailSegments = numberOfTailSegments;
}

bool Snake::getHasGameModeExited()
{
	//return the bool to be used in a different class
	return m_hasGameModeExited;
}
