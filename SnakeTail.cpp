#include "Helpers.h"
#include "Settings.h"
#include "SnakeTail.h"

SnakeTail::SnakeTail()
{
	//This is the default constructor so it will set the values to 0 and character to blank
	initialise(' ', getPositionXYReadOnly(), 0);
}

SnakeTail::SnakeTail(char tailSegmentCharacter, const Vector2& startPositionXY, int numberOfTailSegments)
{
	//This will set the values passed through the parameter
	initialise(tailSegmentCharacter, startPositionXY, numberOfTailSegments);
}

SnakeTail::~SnakeTail()
{
	if (m_pTailSegments != nullptr)
	{
		unrender();
		m_pTailSegments = nullptr;
	}
}

void SnakeTail::update(int numberOfTailSegments, const Vector2& currentSnakePositionXY)
{
	//Set the values that have been passed through from the snake
	m_snakeHeadCurrentPositionX = currentSnakePositionXY.getPositionX();
	m_snakeHeadCurrentPositionY = currentSnakePositionXY.getPositionY();
	m_numberOfTailSegments		= numberOfTailSegments;

	//Unrender the tail and move the tail segment
    unrender();
	movement();
}

void SnakeTail::render()
{
	//Loop through all of the tail segments, draw them and colour each one
	for (int tailSegmentCount = 0; tailSegmentCount < m_numberOfTailSegments; ++tailSegmentCount)
	{
		drawCharacterInPosition(m_snakeTailSegmentCharacter, m_pTailSegments[tailSegmentCount].getPositionXYReadOnly());
		colourCharacter(Settings::Colours::c_lightGreenBox);
	}
}

void SnakeTail::unrender()
{
	//Loop through each tail segment and make it blank to unrender each tail segment
	for (int tailSegmentCount = 0; tailSegmentCount < m_numberOfTailSegments; ++tailSegmentCount)
	{
		drawCharacterInPosition(' ', m_pTailSegments[tailSegmentCount].getPositionXYReadOnly());
	}
}

void SnakeTail::initialise(char tailSegmentCharacter, const Vector2& startPositionXY, int numberOfTailSegments)
{
	//Initialise each of these values
	m_hasSnakeHeadCollided		= false;
	m_snakeTailSegmentCharacter = tailSegmentCharacter;
	m_maxAmountOfTailSegments	= 1000;
	m_numberOfTailSegments		= numberOfTailSegments;
	m_snakeHeadCurrentPositionX = startPositionXY.getPositionX();
	m_snakeHeadCurrentPositionY = startPositionXY.getPositionY();
	m_pTailSegments				= new CharacterObject[m_maxAmountOfTailSegments];
}

void SnakeTail::movement()
{
	//Sets the current segment position by getting the position already set, which would be 0 or garbage for now
	int currentSegmentPositionX = m_pTailSegments[0].getPositionX();
	int currentSegmentPositionY = m_pTailSegments[0].getPositionY();

	//These previous segment position which will be set the set position of the next one
	int previousSegmentPositionX;
	int previousSegmentPositionY;

	//Set position of the first segment of the snake's current position, as it is the first segment
	m_pTailSegments[0].setPositionXY(m_snakeHeadCurrentPositionX, m_snakeHeadCurrentPositionY);

	//Loop through each segment, if it has any
	for (int tailSegmentCount = 1; tailSegmentCount < m_numberOfTailSegments; ++tailSegmentCount)
	{
		//Set the previous segment position
		previousSegmentPositionX = m_pTailSegments[tailSegmentCount].getPositionX();
		previousSegmentPositionY = m_pTailSegments[tailSegmentCount].getPositionY();

		//Set the the current segment position
		m_pTailSegments[tailSegmentCount].setPositionXY(currentSegmentPositionX, currentSegmentPositionY);

		//Using the previous segment position set the current segment position
		currentSegmentPositionX = previousSegmentPositionX;
		currentSegmentPositionY = previousSegmentPositionY;

		//Check if the current segment position is the same as the snake head position
		if (currentSegmentPositionX == m_snakeHeadCurrentPositionX && currentSegmentPositionY == m_snakeHeadCurrentPositionY)
		{
			m_hasSnakeHeadCollided = true;
		}
	}	
}

bool SnakeTail::getHasSnakeHeadCollided()
{
	return m_hasSnakeHeadCollided;
}