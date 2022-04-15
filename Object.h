#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: Object
// Classes Inherited	: Vector2
// Purpose				: To handle objects that will have an update, render and unrender
//-------------------------------------------------------------------------------------------------------------------------
class Object : public Vector2
{
public:
#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: update()
	// Parameters		: None
	// Purpose			: To update the values of a class
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void update()	{};

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: render()
	// Parameters		: None
	// Purpose			: To render the object on to the screen, so its visible
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render()	{};

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: unrender()
	// Parameters		: None
	// Purpose			: To unrender the object on the screen, so its not visible
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void unrender() {};

#pragma endregion
};

#endif // !OBJECT_H