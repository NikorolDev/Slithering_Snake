#include <conio.h>
#include <iostream>

#include "Helpers.h"
#include "MenuPointer.h"
#include "Settings.h"

MenuPointer::MenuPointer()
{
	//This is the default constructor so set the values to 0
	initialise(' ', getPositionXYReadOnly());
}

MenuPointer::MenuPointer(char character, const Vector2& positionXY)
{
	//This will set the values passed through the parameter
	initialise(character, positionXY.getPositionXYReadOnly());
}

MenuPointer::~MenuPointer()
{
}

void MenuPointer::update()
{
	//Unrender the pointer and check for key input
	unrender();
	inputManager();
}

void MenuPointer::render()
{
	//Draw the character pointer
	drawCharacterInPosition(m_pointerCharacter, getPositionXYReadOnly());
}

void MenuPointer::unrender()
{
	//Unrender the pointer
	drawCharacterInPosition(' ', getPositionXYReadOnly());
}

void MenuPointer::initialise(char character, const Vector2& positionXY)
{
	//Initialise/ re-initialise the values and set the variables with values passed through
	m_hasSelected			= false;
	m_pointerCharacter		= character;
	m_pointerPositionX		= positionXY.getPositionX();
	m_pointerPositionY		= positionXY.getPositionY();	

	//Set character and position of the pointer
	setCharacter(m_pointerCharacter);
	setPositionXY(m_pointerPositionX, m_pointerPositionY);
}

void MenuPointer::inputManager()
{
	//Check if a key on the keyboard has been pressed
	if (_kbhit())
	{
		//Set the key that was pressed
		char keyID = _getch();

		//Based on the key pressed it will move the pointer or select the option
		switch (keyID)
		{
			case 'w': //Go up
			{
				//Check if the pointer go any higher
				if (m_pointerPositionY > m_minSelectionPositionY)
				{
					m_pointerPositionY--;
				}
				break;
			}

			case 's': //Go down
			{
				//Check if the pointer go any lower. This check will proof that the pointer will not go any lower than the last button by adding the -1
				if (m_pointerPositionY < (m_maxSelectionPositionY - 1))
				{
					m_pointerPositionY++;
				}
				break;
			}

			case 'e': //Select
			{
				m_hasSelected = true;
				break;
			}
		}
	}

	//Set the position of the pointer as it has been updated
	setPositionXY(m_pointerPositionX, m_pointerPositionY);
}

void MenuPointer::setMinSelectionPositionY(int minPositionY) { m_minSelectionPositionY = minPositionY; }

void MenuPointer::setMaxSelectionPositionY(int maxPositionY) { m_maxSelectionPositionY = maxPositionY; }

bool MenuPointer::getHasSelected() { return m_hasSelected; }