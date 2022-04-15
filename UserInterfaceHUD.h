#ifndef	USERINTERFACEHUD_H
#define	USERINTERFACEHUD_H

#include "Object.h"
#include "Settings.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: MenuPointer
// Classes Inherited	: Object
// Purpose				: To display the HUD area for the player with controls, snake's position and score
//-------------------------------------------------------------------------------------------------------------------------
class UserInterfaceHUD : public Object
{
private:
#pragma region private variables
	int m_currentSnakePositionX; //The current position of the snake on the X
	int m_currentSnakePositionY; //The current position of the snake on the Y
	int m_hudPositionX; //The position of the HUD on the X
	int m_hudPositionY; //The position of the HUD on the Y
	int m_hudHeight; //The height of the HUD
	int m_hudWidth; //The Width of the HUD
	int m_score; //The current score that is recorded

	//The 2D array that will be used to draw the HUD area
	int m_hudMatrix[Settings::HUD::c_hudMaxHeight][Settings::HUD::c_hudMaxWidth];

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise()
	// Parameters		: None
	// Purpose			: To initialise the HUD, by setting the 2D array and set text that won't change
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setHUD()
	// Parameters		: None
	// Purpose			: This will read the csv file of the HUD and set the 2D array with it
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setHUD();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: displayHUDArea()
	// Parameters		: None
	// Purpose			: This will display the HUD area and set text that won't change
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void displayHUDArea();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: displayHUDValues()
	// Parameters		: None
	// Purpose			: This will display HUD values that are constantly updated
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void displayHUDValues();

#pragma endregion

public:
#pragma region constructors and deconstructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: SnakeHead()
	// Parameters		: None
	// Notes			: This will run the initialiser
	// See also			: 
	//---------------------------------------------------------------------------------------------------------------------
	UserInterfaceHUD();

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: SnakeHead()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~UserInterfaceHUD();

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: update(, const Vector2& currentSnakePositionXY, int score)
	// Parameters		: currentSnakePositionXY - the current position of the snake
	//					, score - the current score amount
	// Purpose			: This updater will use the values passed through, such as the snake's position to update the 
	//					,	position display
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void update(const Vector2& positionXY, int score);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: render()
	// Parameters		: None
	// Purpose			: The overridden renderer to render the HUD area and constant text
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;
#pragma endregion
};


#endif // !USERINTERFACEHUD_H
