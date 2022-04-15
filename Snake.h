#ifndef SNAKE_H
#define SNAKE_H

#include "Object.h"
#include "SnakeHead.h"
#include "SnakeTail.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: Snake
// Classes Inherited	: Object
// Purpose				: To handle the snake's whole body, which is the head and tail 
//-------------------------------------------------------------------------------------------------------------------------
class Snake : public Object
{
private:
#pragma region private variables
	bool m_hasGameModeExited; //This will be used to check if the game mode has exited

	char m_snakeCharacter; //This is the character that will represent the snake's body, which are the head and tail

	int m_numberOfTailSegments; //This is the number of tail segments for the tail
	int m_snakePositionX; //The position on the X of the snake, which is represented by the snake head
	int m_snakePositionY; //The position on the Y of the snake, which is represented by the snake head

	SnakeHead m_snakeHead; //A single instance of the snake head
	SnakeTail m_snakeTail; //A single instance of the snake tail

#pragma endregion

#pragma region private frunctions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(char snakeCharacter, int startingSnakePositionX, int startingSnakePositionY, int numberOfTailSegments)
	// Parameters		: snakeCharacter			- the initial desired character to represent the whole of snake body
	//					, startingSnakePositionX	- the desired starting position of the snake on the X
	//					, startingSnakePositionY	- the desired starting position of the snake on the Y
	//					, numberOfTailSegments		- the initial number of tail segments, which would be 0 at start
	// Purpose			: To initialise the snake body by setting the values and with the ones passed through
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise(char snakeCharacter, int startingSnakePositionX, int startingSnakePositionY, int numberOfTailSegments);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: checkGameIsPlaying()
	// Parameters		: None
	// Purpose			: To check if the game is still playing, which checks if player pressed exit or collided with itself
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void checkGameIsPlaying();

#pragma endregion

public:
#pragma region constructors and destructor
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: Snake()
	// Parameters		: None
	// Notes			: To set the values of the snake to 0
	//---------------------------------------------------------------------------------------------------------------------
	Snake();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: Snake(char snakeCharacter, int startingSnakePositionX, int startingSnakePositionY, int numberOfTailSegments)
	// Parameters		: snakeCharacter		- the desired character to represent the snake's whole body
	//					, startPositionX		- the desired position of the snake on X
	//					, startPositionY		- the desired position of the snake on Y
	//					, numberOfTailSegments	- the number of segments the snake should start with
	// Notes			: To set the values of the snake to the values passed through
	//---------------------------------------------------------------------------------------------------------------------
	Snake(char snakeCharacter, int startingSnakePositionX, int startingSnakePositionY, int numberOfTailSegments);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: Snake()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~Snake();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: update()
	// Parameters		: None
	// Purpose			: The overridden updater to update the snake head and the snake tail
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void update() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: render()
	// Parameters		: None
	// Purpose			: The overridden renderer to render the snake head and snake tail
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;

#pragma endregion

#pragma region getters and setters
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setNumberOfTailSegments(int numberOfTailSegments)
	// Parameters		: numberOfTailSegments - sets the number of tail segments for the tail
	// Purpose			: To set the number of tail segments to render and update each one
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setNumberOfTailSegments(int numberOfTailSegments);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getHasGameModeExited()
	// Parameters		: None
	// Purpose			: To return the boolean that checks if the game is still playing
	// Returns			: Returns the boolean that will check if the player has exited the game mode
	//---------------------------------------------------------------------------------------------------------------------
	bool getHasGameModeExited();

#pragma endregion

};

#endif // !SNAKE_H
