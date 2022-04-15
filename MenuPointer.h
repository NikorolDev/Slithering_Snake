#ifndef MENUPOINTER_H
#define MENUPOINTER_H

#include "CharacterObject.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: MenuPointer
// Classes Inherited	: CharacterObject
// Purpose				: To point at the buttons so the player knows what they are selecting
//-------------------------------------------------------------------------------------------------------------------------
class MenuPointer : public CharacterObject
{
private:
#pragma region private variables
	bool m_hasSelected; //This checks if the player has selected

	char m_pointerCharacter; //The character that represents the pointer

	int m_controlsTextPositionX; //The position of the controls text on the X axis
	int m_controlsTextPositionY; //The position of the controls text on the Y axis
	int m_pointerPositionX; //The position of the pointer on the X
	int m_pointerPositionY; //The position of the pointer on the Y
	int m_minSelectionPositionY; //The minimum selection so that the pointer doesn't go above the buttons
	int m_maxSelectionPositionY; //The maximum selection so that the pointer doesn't go below the buttons

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(char character, int positionX, int positionY)
	// Parameters		: character		- the initial desired character to represent the whole of snake body
	//					, startPositionXY		- the desired position of the pointer on the X and Y
	// Purpose			: To initialise the snake body by setting the values and with the ones passed through
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise(char character, const Vector2& positionXY);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: inputManager()
	// Parameters		: None
	// Purpose			: To manage keys that are being pressed to determine the actions, such as where the pointer will go
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void inputManager();
#pragma endregion

public:
#pragma region constructors and deconstructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: SnakeHead()
	// Parameters		: None
	// Notes			: To set the values of the pointer to 0 and blank
	// See also			: 
	//---------------------------------------------------------------------------------------------------------------------
	MenuPointer();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: MenuPointer(char character, const Vector2& positionXY)
	// Parameters		: character		- the desired character to represent the pointer
	//					, positionXY	- the desired starting position of the pointer on X and Y
	// Notes			: To set the values of the pointer to the values passed through
	//---------------------------------------------------------------------------------------------------------------------
	MenuPointer(char character, const Vector2& positionXY);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: SnakeHead()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~MenuPointer();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: update()
	// Parameters		: None
	// Purpose			: The overridden updater to check for input and move the pointer
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void update() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: render()
	// Parameters		: None
	// Purpose			: The overridden renderer to render the render
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: unrender()
	// Parameters		: None
	// Purpose			: The overridden unrenderer to unrender the pointer
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void unrender() override;

#pragma endregion

#pragma region getters and setters
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setMinSelectionPositionY(int minPositionY)
	// Parameters		: minPositionY - sets the desired minimum selection position
	// Purpose			: To set the minimum selection position so that the pointer does not go above the first button on 
	//					,	any screen that has buttons
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setMinSelectionPositionY(int minPositionY);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setMaxSelectionPositionY(int maxPositionY)
	// Parameters		: maxPositionY - sets the desired maximum selection position
	// Purpose			: To set the maximum selection position so that the pointer does not go below the below button on 
	//					,	any screen that has buttons
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setMaxSelectionPositionY(int maxPositionY);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getHasSelected()
	// Parameters		: None
	// Purpose			: To get the boolean that checks if the pointer has selected on the button position
	// Returns			: Returns the boolean that will check if the pointer has selected on anything
	//---------------------------------------------------------------------------------------------------------------------
	bool getHasSelected();

#pragma endregion
};

#endif // !MENUPOINTER_H
