#ifndef FRUIT_H
#define FRUIT_H

#include "CharacterObject.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: Snake
// Classes Inherited	: CharacterObject
// Purpose				: To render the fruit and randomise the position, which will increment the tail segment 
//-------------------------------------------------------------------------------------------------------------------------
class Fruit : public CharacterObject
{
private:
#pragma region private variables
	char m_fruitCharacter; //This character will represent the fruit

	int m_fruitPositionX; //The position of the fruit on the X
	int m_fruitPositionY; //The position of the fruit on the Y

#pragma endregion

#pragma region private frunctions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(char fruitCharacter, int positionX, int positionY)
	// Parameters		: fruitCharacter	- the initial desired character to represent the fruit
	//					, positionX			- the desired position on the X
	//					, positionY			- the desired position on the Y
	// Purpose			: To initialise the fruit class by setting the values and with the ones passed through
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise(char fruitCharacter, int positionX, int positionY);

#pragma endregion

public:
#pragma region constructors and destructor
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: Fruit()
	// Parameters		: None
	// Notes			: To set the values of the snake to 0 and blank
	//---------------------------------------------------------------------------------------------------------------------
	Fruit();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: Fruit(char fruitCharacter, int positionX, int positionY)
	// Parameters		: fruitCharacter	- the desired character to represent the fruit
	//					, positionX			- the desired position of the fruit on X
	//					, positionY			- the desired position of the fruit on Y
	// Notes			: To set the values of the fruit to the values passed through
	//---------------------------------------------------------------------------------------------------------------------
	Fruit(char fruitCharacter, int positionX, int positionY);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: Fruit()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~Fruit();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: render()
	// Parameters		: None
	// Purpose			: The overridden renderer to render the fruit
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: unrender()
	// Parameters		: None
	// Purpose			: The overridden unrenderer will unrendener the fruit
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void unrender() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: randomiseFruitPosition()
	// Parameters		: None
	// Purpose			: This set a random position of the next fruit
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void randomiseFruitPosition();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: randomiseFruitPosition(int wallRow, int wallColumn, int wallID)
	// Parameters		: wallRow		- the wall row position
	//					, wallColumn	- the wall column position
	//					, int wallID	- the identifier of the wall, which is marked by 1 or higher
	// Purpose			: This set a random position of th next fruit and avoids the walls that on the playing area
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void randomiseFruitPosition(int wallRow, int wallColumn, int wallID);

#pragma endregion

#pragma region getters and setters
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setHasFruitRendered(bool hasFruitRendered)
	// Parameters		: hasFruitRendered - sets the boolean for rendering the fruit
	// Purpose			: To set the boolean that will allow the fruit to rerender
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setHasFruitRendered(bool hasFruitRendered);

#pragma endregion
};

#endif // !FRUIT_H
