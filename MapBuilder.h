#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include "Object.h"
#include "Settings.h"

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: Snake
// Classes Inherited	: Object
// Purpose				: To build the map from the csv file
//-------------------------------------------------------------------------------------------------------------------------
class MapBuilder : public Object
{
private:
#pragma region private variables
	int m_mapID; //The ID of the map to load

	int m_mapHeight; //The height of the map
	int m_mapWidth; //The width of the map

	//The 2D array that will store the selected map and render from it
	int m_matrixMap[Settings::Map::c_mapMaxHeight][Settings::Map::c_mapMaxWidth];

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise(int mapID)
	// Parameters		: mapID - the ID of the map to be used to read from a csv file
	// Purpose			: To initialise the map by setting the 2D array from a csv file
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise(int mapID);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: chosenMap()
	// Parameters		: None
	// Purpose			: This will initialise the 2D array by reading the csv file of the selected map
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void chosenMap();

#pragma endregion

public:
#pragma region constructors and destructor
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: MapBuilder()
	// Parameters		: None
	// Notes			: To set the map to nothing
	//---------------------------------------------------------------------------------------------------------------------
	MapBuilder();

	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: MapBuilder(int mapID)
	// Parameters		: mapID - the desired map to load 
	// Notes			: To set the map based on the mapID that's been set to
	//---------------------------------------------------------------------------------------------------------------------
	MapBuilder(int mapID);

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: Snake()
	// Parameters		: None
	// Notes			: Default destructor will simply delete itself
	//---------------------------------------------------------------------------------------------------------------------
	~MapBuilder();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: drawMap()
	// Parameters		: None
	// Purpose			: This will draw map on to the screen
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void drawMap();

#pragma endregion

#pragma region getters and setters
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getMapWall(int mapRow, int mapColumn)
	// Parameters		: mapRow		- the map row from that is passed from the loop mainly
	//					, mapColumn		- the map column from that is passed from the loop mainly
	// Purpose			: To return the 2D array element value
	// Returns			: Returns the integer of of map element value that the loop will be on, for example
	//---------------------------------------------------------------------------------------------------------------------
	int getMapWall(int mapRow, int mapColumn);

#pragma endregion
};

#endif // !MAPBUILDER_H
