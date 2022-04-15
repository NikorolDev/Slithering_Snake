#include "FileReadingHeaders.h"
#include "Helpers.h"
#include "MapBuilder.h"

MapBuilder::MapBuilder()
{
	//Set the map to nothing
	initialise(0);
}

MapBuilder::MapBuilder(int mapID)
{
	//Set the map based on what was passed through
	initialise(mapID);
}

MapBuilder::~MapBuilder()
{
}

void MapBuilder::drawMap()
{
	//Set the position of where the map should start drawing
	setPositionXY(Settings::Positions::c_consoleStartPositionX, Settings::Positions::c_consoleStartPositionY);
	moveToXYPosition(getPositionXYReadOnly());

	//Start the first loop to draw the map from the matrix array to draw the rows/ height of the map
	for (int mapRowCounter = 0; mapRowCounter < m_mapHeight; ++mapRowCounter)
	{
		//Then start another loop which will draw the columns/width of the map
		for (int mapColumnCounter = 0; mapColumnCounter < m_mapWidth; ++mapColumnCounter)
		{
			//switch between the array element, which will be the integer values inside the matrix
			switch (m_matrixMap[mapRowCounter][mapColumnCounter])
			{
				//0 inside the array is free area, which the player can move around in
				case 0:
				{
					colourCharacter(Settings::Colours::c_blackBox);
					std::cout << " ";
					break;
				}

				//1 inside the array is the walls, which will be used as colliders
				case 1:
				{
					colourCharacter(Settings::Colours::c_darkGreenBox);
					std::cout << "W";
					break;
				}

				//2 iside the array is also walls, but in the "Two Rivers" map its a water tile
				case 2:
				{
					colourCharacter(Settings::Colours::c_cyanBox);
					std::cout << "W";
				}
			}
		}
		//Go to a new line when the row is finished
		std::cout << '\n';
	}
	//Set the console font colour to default
	colourCharacter(Settings::Colours::c_defaultConsoleColour);
}

int MapBuilder::getMapWall(int mapRow, int mapColumn)
{
	return m_matrixMap[mapRow][mapColumn];
}

void MapBuilder::initialise(int mapID)
{
	//Initialise/ reinitialise these values
	m_mapID		= mapID;
	m_mapHeight = Settings::Map::c_mapMaxHeight;
	m_mapWidth	= Settings::Map::c_mapMaxWidth;
	
	//Choose map, by initialising the 2D array from a csv file
	chosenMap();
}

void MapBuilder::chosenMap()
{
	//Create a string that will hold the location of the csv file
	std::string fileName;

	switch (m_mapID) //Based on the map ID that was via constructor
	{
		case 1: //Classic map
		{
			fileName = "csvFiles/Map1.csv";
			break;
		}

		case 2: //Over The Hedges map
		{
			fileName = "csvFiles/Map2.csv";
			break;
		}

		case 3: //Two Rivers map
		{
			fileName = "csvFiles/Map3.csv";
			break;
		}

		case 4: //The woods map
		{
			fileName = "csvFiles/Map4.csv";
			break;
		}
	}

	//Store the file in an ifstream variable
	std::ifstream mapFile(fileName);

	//Loop through the row of the file first
	for (int mapRow = 0; mapRow < m_mapHeight; ++mapRow)
	{
		//Creating this string variable will get the whole line of the csv file
		std::string fileRow;
		std::getline(mapFile, fileRow);

		//Create an instance of the file row by creating a string stream and store it there
		std::stringstream stringStreamMapRow(fileRow);

		//Loop through the whole column to start adding values to the 2d array
		for (int mapColumn = 0; mapColumn < m_mapWidth; ++mapColumn)
		{
			std::string mapElement; //Create another string variable that will store each element of the csv file
			std::getline(stringStreamMapRow, mapElement, ','); //Using stringStreamRow, split the row with a ',' and store it in titleElement, which will hold that single value from the row

			//Create an instance of the element, which will add it to the 2d array
			std::stringstream converter(mapElement);
			converter >> m_matrixMap[mapRow][mapColumn];
		}
	}
}
