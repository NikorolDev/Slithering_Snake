#ifndef SNAKETAIL_H
#define SNAKETAIL_H

#include "CharacterObject.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: SnakeTail
// Classes Inherited	: Object
// Purpose				: To handle the movement of the whole tail and render each segment
//-------------------------------------------------------------------------------------------------------------------------
class SnakeTail : public Object
{
private:
#pragma region private variables
	bool m_hasSnakeHeadCollided; //To check if the snake head has collided with the tail

	char m_snakeTailSegmentCharacter; //The character to represent each segment

	int m_maxAmountOfTailSegments; //Max amount of tail segments that the tail will have
	int m_numberOfTailSegments; //The number of tail segments to draw and update 
	int m_snakeHeadCurrentPositionX; //The current position of the snake head on the X
	int m_snakeHeadCurrentPositionY; //The current position of the snake head on the Y

	CharacterObject* m_pTailSegments; //The pointer that will allocate max amount of segments to the heap

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(char snakeHeadCharacter, const Vector2& startingPositionXY)
	// Parameters		: snakeHeadCharacter	- the initial desired character to represent the snake head
	//					, startPositionXY		- the desired starting position of the snake tail on the X and Y
	//					, numberOfTailSegments	- the initial number of tail segments
	// Purpose			: To initialise the snake tail by setting the values passed through and the remaining 
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise(char tailSegmentCharacter, const Vector2& startPositionXY, int numberOfTailSegments);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: movement()
	// Parameters		: None
	// Purpose			: To move the snake tail based that follows the snake head
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void movement();

#pragma endregion

public:
#pragma region constructors and destructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: SnakeTail()
	// Parameters		: None
	// Notes			: To set the values of the snake tail to 0
	// See also			: 
	//---------------------------------------------------------------------------------------------------------------------
	SnakeTail();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: SnakeTail(char snakeHeadCharacter, const Vector2& startingPositionXY, int numberOfTailSegments)
	// Parameters		: snakeHeadCharacter	- the desired character to represent the snake head
	//					, startPositionXY		- the desired starting position of the snake head on X and Y
	//					, numberOfTailSegments	- the initial number of tail segments
	// Notes			: To set the values of the snake tail to the values passed through
	//---------------------------------------------------------------------------------------------------------------------
	SnakeTail(char tailSegmentCharacter, const Vector2& startPositionXY, int numberOfTailSegments);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: SnakeHead()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself and set the pointer to nullptr
	//---------------------------------------------------------------------------------------------------------------------
	~SnakeTail();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: update(int numberOfTailSegments, const Vector2& currentSnakePositionXY)
	// Parameters		: numberOfTailSegments - the amount of segments that will updated and rendered
	//					, currentSnakePositionXY - the current position of the snake
	// Purpose			: This updater will use the values passed through, such as the snake's position to update the each 
	//					,	tail segment
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void update(int numberOfTailSegments, const Vector2& currentSnakePositionXY);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: render()
	// Parameters		: None
	// Purpose			: The overridden renderer to render each tail segment
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render() override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: unrender()
	// Parameters		: None
	// Purpose			: The overridden unrenderer to unrender each snake tail
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void unrender() override;	

#pragma endregion

#pragma region getters and setters
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getHasSnakeHeadCollided()
	// Parameters		: None
	// Purpose			: To return the boolean that checks if the snake head has collided with the tail
	// Returns			: Returns the boolean that checks if the snake head has collided with the tail
	//---------------------------------------------------------------------------------------------------------------------
	bool getHasSnakeHeadCollided();

#pragma endregion
};

#endif // !SNAKETAIL_H
