#include "Vector2.h"

void Vector2::initialise(int positionX, int positionY)
{
	//Positions X and Y will be set to what was passed through constructors
	m_positionX = positionX;
	m_positionY = positionY;
}

Vector2::Vector2()
{
	//As this is the default constructor it will set the position to 0,0
	initialise(0, 0);
}

Vector2::Vector2(int positionX, int positionY)
{
	//It will set the positions based on the parameter passed through
	initialise(positionX, positionY);
}

Vector2::~Vector2()
{

}

void Vector2::setPositionXY(int positionX, int positionY)
{
	//Set the position XY passed through
	m_positionX = positionX;
	m_positionY = positionY;
}

Vector2& Vector2::getPositionXYModifiable()
{
	//return this Vector2 reference as modifiable
	return *this;
}

const Vector2& Vector2::getPositionXYReadOnly() const
{
	//return this Vector2 reference as read only
	return *this;
}

int Vector2::getPositionX() const
{
	//return position on the x axis
	return m_positionX;
}

int Vector2::getPositionY() const
{
	//return position on the y axis
	return m_positionY;
}
