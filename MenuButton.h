#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <iostream>

#include "Object.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: MenuButton
// Classes Inherited	: Object
// Purpose				: To mainly render the button that will be mainly made by the text
//-------------------------------------------------------------------------------------------------------------------------
class MenuButton : public Object
{
private:
#pragma region private variables
	int m_buttonPositionX; //The position on the x of where the button will be placed
	int m_buttonPositionY; //The position on the y of where the button will be placed

	//The text for the button 
	std::string m_buttonText; 

#pragma endregion
public:
#pragma region constructors and deconstructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor		: MenuButton()
	// Parameters		: none
	// Notes			: Initialises the variables to 0 and " "
	//---------------------------------------------------------------------------------------------------------------------
	MenuButton();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor		: MenuButton()
	// Parameters		: const string& buttonText
	//					, const Vector& buttonPosition
	// Notes			: Initialises the variables to those passed in
	//---------------------------------------------------------------------------------------------------------------------
	MenuButton(const std::string& buttonText, const Vector2& buttonPosition);

	//---------------------------------------------------------------------------------------------------------------------
	// Deconstructor	: GameTitleElement()
	// Parameters		: none
	// Notes			: Will deconstruct the whole class as nothing special is deconstructed
	//---------------------------------------------------------------------------------------------------------------------
	~MenuButton();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: render()
	// Parameters		: none
	// Purpose			: This overridden function from the Object class will render the buttons on the screen
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;

#pragma endregion
};

#endif // !MENUBUTTON_H
