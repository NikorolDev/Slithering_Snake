#ifndef GAMETITLEELEMENT_H
#define GAMETITLEELEMENT_H

#include "Object.h"
#include "Settings.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: GameTitleElement
// Classes Inherited	: Object
// Purpose				: To display the game title by reading the csv file which has the title made
//-------------------------------------------------------------------------------------------------------------------------
class GameTitleElement : public Object
{
private:
#pragma region private variables
	int m_gameTitleHeight; //The height that the title has
	int m_gameTitlePositionX; //The position on the x of where the title will be placed 
	int m_gameTitlePositionY; //The position on the y of where the title will be placed 
	int m_gameTitleWidth; //The width that the title has

	//The 2d array that will store the title and render it from
	int m_gameTitleMatrix[Settings::Title::c_titleHeight][Settings::Title::c_titleWidth];

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: setTitle()
	// Parameters		: none
	// Purpose			: This will set the map by reading the csv file and set the values to the 2d array
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setTitle();

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: displayTitle()
	// Parameters		: none
	// Purpose			: This will render the map fro the 2d array
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	void displayTitle();

#pragma endregion

public:
#pragma region constructors and deconstructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor		: GameTitleElement()
	// Parameters		: none
	// Notes			: Initialises the variables, sets the position of the game title object and sets the title to the
	//					, 2d array
	//---------------------------------------------------------------------------------------------------------------------
	GameTitleElement();

	//---------------------------------------------------------------------------------------------------------------------
	// Deconstructor	: GameTitleElement()
	// Parameters		: none
	// Notes			: Will destruct the whole class as nothing special is destructed
	//---------------------------------------------------------------------------------------------------------------------
	~GameTitleElement();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: render()
	// Parameters		: none
	// Purpose			: This overridden function from the Object class will render the title on the screen
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;

#pragma  endregion
};

#endif // ! GAMETITLEELEMENT_H
