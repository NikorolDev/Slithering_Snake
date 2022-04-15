#ifndef VECTOR2_H
#define VECTOR2_H

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: Vector2
// Classes Inherited	: None
// Purpose				: To handle a 2D Vector for position. This is so that the derived class can use the getters and 
//						,	setters
//-------------------------------------------------------------------------------------------------------------------------
class Vector2
{
private:
#pragma region private variables
	int m_positionX; //Position on the x axis
	int m_positionY; //Position on the y axis

#pragma endregion

#pragma  region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(int positionX, int positionY)
	// Parameters		: positionX - the initial desired X and Y positions
	// Purpose			: To initialise positionX and Y into those multiple constructors
	// Returns			: Nothing
	//--------------------------------------------------------------------------------------------------------------------
	void initialise(int positionX, int positionY);

#pragma endregion

public:
#pragma region constructors and destructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: Vector2()
	// Parameters		: None
	// Notes			: To set a 2D vector of position XY to 0
	//---------------------------------------------------------------------------------------------------------------------
	Vector2();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: Vector2()
	// Parameters		: positionX - sets desired position on the x axis
	//					, positionY - sets desired position on the y axis
	// Notes			: To set a 2D vector of position XY to desired values
	//---------------------------------------------------------------------------------------------------------------------
	Vector2(int positionX, int positionY);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: Vector2()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~Vector2();

#pragma endregion

#pragma region getters and setters
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setPositionXY(int positionX, int positionY)
	// Parameters		: positionX - sets the position on the x axis.
	//					, positionY - sets the position on the y axis.
	// Purpose			: To set the 2D Vector positions to the desired values
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setPositionXY(int positionX, int positionY);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getPositionXYModifiable()
	// Parameters		: none
	// Purpose			: To get the reference Vector 2D positions this will allow the values to be tampered with
	// Returns			: Returns a reference of a Vector2
	//---------------------------------------------------------------------------------------------------------------------
	Vector2& getPositionXYModifiable();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getPositionXYReadOnly()
	// Parameters		: none
	// Purpose			: To get the reference Vector 2D positions and as a read only so no values are changed
	// Returns			: Returns a read only reference of a Vector2
	//---------------------------------------------------------------------------------------------------------------------
	const Vector2& getPositionXYReadOnly() const;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getPositionX()
	// Parameters		: None
	// Purpose			: To return positionX of the object's Vector2 base class
	// Returns			: Returns position on the x
	//---------------------------------------------------------------------------------------------------------------------
	int getPositionX() const;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getPositionY()
	// Parameters		: None
	// Purpose			: To return positionY of the object's Vector2 base class 
	// Returns			: Returns position on the y
	//---------------------------------------------------------------------------------------------------------------------
	int getPositionY() const;

#pragma endregion
};

#endif // !VECTOR2_H
