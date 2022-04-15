#include <ctime>
#include <stdlib.h>

#include "Fruit.h"
#include "Helpers.h"
#include "Settings.h"

Fruit::Fruit()
{
	//This is the default constructor so set the values to 0
	initialise(' ', 0, 0);
}

Fruit::Fruit(char fruitCharacter, int positionX, int positionY)
{
	//This will set the values passed through the parameter
	initialise(fruitCharacter, positionX, positionY);
}

Fruit::~Fruit()
{

}

void Fruit::render()
{
	//Colour the fruit blue and draw the character
	colourCharacter(Settings::Colours::c_darkBlueBox);
	drawCharacterInPosition(m_fruitCharacter, getPositionXYReadOnly());
}

void Fruit::unrender()
{
	//Unrender the fruit 
	drawCharacterInPosition(' ', getPositionXYReadOnly());
}

void Fruit::randomiseFruitPosition()
{
	//This will constantly randomise the fruit in different places
	srand((int) time(0));

	//Randomise the position of the fruit
	m_fruitPositionX = ( rand() % 28 ) + 1;
	m_fruitPositionY = ( rand() % 28 ) + 1;

	//Set the new positions of the fruit
	setPositionXY(m_fruitPositionX, m_fruitPositionY);
}

void Fruit::randomiseFruitPosition(int wallRow, int wallColumn, int wallID)
{
	//This will constantly randomise the fruit in different places
	srand((int) time(0));

	//Randomise the position of the fruit
	m_fruitPositionX = ( rand() % 28 ) + 1;
	m_fruitPositionY = ( rand() % 28 ) + 1;

	//Check if the wall row and column is the same as the randomised fruit position and if it is located not on the wall
	if (wallRow == m_fruitPositionY && wallColumn == m_fruitPositionX && wallID == 0)
	{
		//Set the position of the fruit
		setPositionXY(m_fruitPositionX, m_fruitPositionY);
	}
	//This will loop again until the position is set to where they can be picked up
}

void Fruit::initialise(char fruitCharacter, int positionX, int positionY)
{
	//Initialise these values with ones that are passed through
	m_fruitCharacter	= fruitCharacter;
	m_fruitPositionX	= positionX;
	m_fruitPositionY	= positionY;

	//Set the position of the fruit
	setPositionXY(m_fruitPositionX, m_fruitPositionY);
}