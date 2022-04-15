#include "CharacterObject.h"

void CharacterObject::initialise(char character)
{
	//Character will be set to what was passed through constructors
	m_character = character;
}

CharacterObject::CharacterObject()
{
	//As this is the default constructor it will set character as blank
	initialise(' ');
}

CharacterObject::CharacterObject(char character)
{
	//It will set the character based on the parameter passed through
	initialise(character);
}

CharacterObject::CharacterObject(char character, const Vector2& positionXY)
{
	//Set the character passed through and set the position XY of the object
	initialise(character);
	setPositionXY(positionXY.getPositionX(), positionXY.getPositionY());
}

CharacterObject::~CharacterObject()
{

}

void CharacterObject::setCharacter(char character)
{
	//Set the character of this object
	m_character = character;
}

char CharacterObject::getCharacter()
{
	//Return character
	return m_character;
}
