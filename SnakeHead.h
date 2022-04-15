#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "CharacterObject.h"
#include "EnumSnakeControls.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: SnakeHead
// Classes Inherited	: CharacterObject
// Purpose				: To handle the movement of the whole as the snake head is front
//-------------------------------------------------------------------------------------------------------------------------
class SnakeHead : public CharacterObject
{
private:
#pragma region private variables
	bool m_hasExitedGameMode; //This checks if the game mode has exited, which take it back to the main menu

	char m_snakeHeadCharacter; //The character that will represent the snake's head

	//These positions will be used for the tail to follow the snake's head
	int m_currentSnakePositionX; //The current position of the snake's head on X
	int m_currentSnakePositionY; //The current position of the snake's head on Y

	EnumSnakeControls m_snakeControls; //An instance of the enum class which will set the direction of the snake head

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(char snakeHeadCharacter, const Vector2& startingPositionXY)
	// Parameters		: snakeHeadCharacter	- the initial desired character to represent the snake head
	//					, startPositionXY		- the desired starting position of the snake head on the X and Y
	// Purpose			: To initialise the snake head by setting the values passed through and the remaining 
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise(char snakeHeadCharacter, const Vector2& startingPositionXY);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: inputManager()
	// Parameters		: None
	// Purpose			: To manage keys that are being pressed to determine the actions, such as direction 
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void inputManager();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: movement()
	// Parameters		: None
	// Purpose			: To move the snake head, based on the game controls set
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void movement();

#pragma endregion
public:
#pragma region constructors and destructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: SnakeHead()
	// Parameters		: None
	// Notes			: To set the values of the snake head to 0
	// See also			: 
	//---------------------------------------------------------------------------------------------------------------------
	SnakeHead();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: SnakeHead(char snakeHeadCharacter, const Vector2& startingPositionXY)
	// Parameters		: snakeHeadCharacter	- the desired character to represent the snake head
	//					, startPositionXY		- the desired starting position of the snake head on X and Y
	// Notes			: To set the values of the snake head to the values passed through
	//---------------------------------------------------------------------------------------------------------------------
	SnakeHead(char snakeHeadCharacter, const Vector2& startingPositionXY);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: SnakeHead()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~SnakeHead();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: update()
	// Parameters		: None
	// Purpose			: The overridden updater to check for input and move the snake head
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void update() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: render()
	// Parameters		: None
	// Purpose			: The overridden renderer to render the snake head and colour it
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: unrender()
	// Parameters		: None
	// Purpose			: The overridden unrenderer to unrender the snake head
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void unrender() override;

#pragma endregion

#pragma region getters and setters
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getHasExitedGameMode()
	// Parameters		: None
	// Purpose			: To return the boolean that allows the player to leave the game
	// Returns			: Returns the boolean that will set game to be exited to the main menu
	//---------------------------------------------------------------------------------------------------------------------
	bool getHasExitedGameMode();

#pragma endregion
};

#endif // !SNAKEHEAD_H
