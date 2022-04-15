#ifndef HELPERS_H
#define HELPERS_H

#include "Vector2.h"

//---------------------------------------------------------------------------------------------------------------------
// Function name	: moveToXYPosition(const Vector2& positionXY)
// Parameters		: positionXY - the position of where to move the cursor
// Purpose			: To move the cursor to the desired position 
// Returns			: Nothing
//---------------------------------------------------------------------------------------------------------------------
void moveToXYPosition(const Vector2& positionXY);

//---------------------------------------------------------------------------------------------------------------------
// Function name	: drawCharacterInPosition(char character, const Vector2& positionXY)
// Parameters		: character - the chacter that will be drawn on the screen
//					, positionXY - the position of where to move the cursor
// Purpose			: To draw the character to the desired position
// Returns			: Nothing
//---------------------------------------------------------------------------------------------------------------------
void drawCharacterInPosition(char character, const Vector2& positionXY);

//---------------------------------------------------------------------------------------------------------------------
// Function name	: colourCharacter(int colourID)
// Parameters		: colourID - the colour of the font that will be printed
// Purpose			: To colour the character to make graphucally pleasing
// Returns			: Nothing
//---------------------------------------------------------------------------------------------------------------------
void colourCharacter(int colourID);

//This macro will safely delete a normal pointer
#define SAFE_DELETE(pointer)	\
if(pointer)						\
{								\
	delete pointer;				\
	pointer = nullptr;			\
}

//This macro will safely delete a pointer array
#define SAFE_DELETE_ARRAY(pointer)	\
if(pointer)							\
{									\
	delete[] pointer;				\
	pointer = nullptr;				\
}						



#endif // !HELPERS_H