#ifndef CHARACTEROBJECT_H
#define CHARACTEROBJECT_H

#include "Object.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: CharacterObject
// Classes Inherited	: Object
// Purpose				: To handle a character objects that will be only a single character. This is also to set the 
//						,	character of the object
//-------------------------------------------------------------------------------------------------------------------------
class CharacterObject : public Object
{
private:
#pragma region private variables
	char m_character; // A single character that will represent the object

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(char character)
	// Parameters		: character - the initial desired character
	// Purpose			: To initialise the m_character into those multiple constructors
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise(char character);

#pragma endregion

public:
#pragma region constructors and destructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: CharacterObject()
	// Parameters		: None
	// Notes			: To set the character of the character to blank
	//---------------------------------------------------------------------------------------------------------------------
	CharacterObject();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: CharacterObject(char character)
	// Parameters		: character - sets desired character 
	// Notes			: To set the desired character passed through
	//---------------------------------------------------------------------------------------------------------------------
	CharacterObject(char character);

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: CharacterObject(char character)
	// Parameters		: character - sets desired character 
	//					, positionXY - sets desired Vector2 for position
	// Notes			: To set the desired character and position passed through 
	//---------------------------------------------------------------------------------------------------------------------
	CharacterObject(char character, const Vector2& positionXY);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: CharacterObject()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~CharacterObject();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setCharacter(char character)
	// Parameters		: character - sets the character for the object
	// Purpose			: To set the character to represent the object that is derived from this class
	// Returns			: Nothing	//---------------------------------------------------------------------------------------------------------------------
	void setCharacter(char character);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getCharacter()
	// Parameters		: none
	// Purpose			: To return the character that represents the object
	// Returns			: Returns character
	//---------------------------------------------------------------------------------------------------------------------
	char getCharacter();

#pragma endregion
};

#endif // !CHARACTEROBJECT_H
