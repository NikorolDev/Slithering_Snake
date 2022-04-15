#include "Helpers.h"
#include "MenuButton.h"

MenuButton::MenuButton()
//Initialised values before being constructed
	: m_buttonPositionX (0)
	, m_buttonPositionY (0)
	, m_buttonText		(" ")
{
}

MenuButton::MenuButton(const std::string& buttonText, const Vector2 &buttonPosition)
{
	//Set the button text on what was passed in and set position from the Vector 2 passed in
	m_buttonText = buttonText;
	m_buttonPositionX = buttonPosition.getPositionX();
	m_buttonPositionY = buttonPosition.getPositionY();
	setPositionXY(m_buttonPositionX, m_buttonPositionY);
}

MenuButton::~MenuButton()
{
}

void MenuButton::render()
{
	//Move the cursor to where the button will be positioned and render the text
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << m_buttonText;
}
