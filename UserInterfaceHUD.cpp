#include "FileReadingHeaders.h"
#include "Helpers.h"
#include "UserInterfaceHUD.h"

UserInterfaceHUD::UserInterfaceHUD()
//Initialised values before being constructed
	: m_hudHeight (Settings::HUD::c_hudMaxHeight)
	, m_hudWidth (Settings::HUD::c_hudMaxWidth)
{
	//This will initialise values and the 2D array
	initialise();
}

UserInterfaceHUD::~UserInterfaceHUD()
{

}

void UserInterfaceHUD::update(const Vector2& snakePositionXY, int score)
{
	//Update these values with the ones passed through to keep the player up to date with what is going on
	m_currentSnakePositionX = snakePositionXY.getPositionX();
	m_currentSnakePositionY = snakePositionXY.getPositionY();
	m_score = score;

	//Display those passed through values
	displayHUDValues();
}

void UserInterfaceHUD::render()
{
	displayHUDArea();
}

void UserInterfaceHUD::initialise()
{	
	//Initialise/ re-initialise these values
	m_hudPositionX			= Settings::HUD::c_hudPositionX;
	m_hudPositionY			= Settings::HUD::c_hudPositionY;

	//Set the position and the HUD through a 2D array
	setPositionXY(m_hudPositionX, m_hudPositionY);
	setHUD();
}

void UserInterfaceHUD::setHUD()
{
	//Create a string to hold the file address of where the HUD is located
	std::string hudFile = "csvFiles/HUD.csv";

	//Store the file in an ifstream variable
	std::ifstream csvFile(hudFile);

	//Loop through the row of the file first
	for (int hudRowCounter = 0; hudRowCounter < m_hudHeight; ++hudRowCounter)
	{
		//Creating this string variable will get the whole line of the csv file
		std::string fileRow;
		std::getline(csvFile, fileRow);

		//Create an instance of the file row by creating a string stream and store it there
		std::stringstream stringStreamRow(fileRow);

		//Loop through the whole column to start adding values to the 2d array
		for (int hudColumnCounter = 0; hudColumnCounter < m_hudWidth; ++hudColumnCounter)
		{
			std::string hudElement; //Create another string variable that will store each element of the csv file
			std::getline(stringStreamRow, hudElement, ','); //Using stringStreamRow, split the row with a ',' and store it in hudElement, which will hold that single value from the row

			//Create an instance of the element, which will add it to the 2d array
			std::stringstream converter(hudElement);
			converter >> m_hudMatrix[hudRowCounter][hudColumnCounter];
		}
	}
}

void UserInterfaceHUD::displayHUDArea()
{
	//We make a local variable of hudPositionY as we dont need to update hudPositionY to draw the HUD and reset it again
	int hudRowPosition = m_hudPositionY;

	//Loop through the rows of the HUD first
	for (int hudRowCounter = 0; hudRowPosition < m_hudHeight; ++hudRowCounter)
	{
		//On each row set the position of our row and move the cursor to that position.  
		//Every time we render the HUDit will start from 0y, but then it will move to next line until all rows are completed
		setPositionXY(m_hudPositionX, hudRowPosition);
		moveToXYPosition(getPositionXYReadOnly());

		//Loop through each column which will be each element 
		for (int hudColumnCounter = 0; hudColumnCounter < m_hudWidth; ++hudColumnCounter)
		{
			//Switch between each element in where the nested loop is in currently
			switch (m_hudMatrix[hudRowCounter][hudColumnCounter])
			{
				case 0: //If the element value is 0
				{
					//Set the colour of the text to be black with black background and output a character
					//Setting the colour will also prevent this character being coloured as a different colour set before
					colourCharacter(Settings::Colours::c_blackBox);
					std::cout << " ";
					break;
				}

				case 1: //If element value is 0
				{
					//Set the colour of the text to white with white background and output a character
					colourCharacter(Settings::Colours::c_whiteBox);
					std::cout << "W";
				}
			}
		}

		//When the column has finished rendering move to next row
		hudRowPosition++;
	}
	
	//Set the defaul colour
	colourCharacter(Settings::Colours::c_defaultConsoleColour);

	//In order to set text consistently throughout the HUD, this code will keep setting position and move the cursor to that position and output the text
	//Title
	setPositionXY(Settings::HUD::c_hudTitlePositionX, Settings::HUD::c_hudTitlePositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "Slithering Snake";

	//Controls Heading
	setPositionXY(Settings::HUD::c_hudControlsHeadingPositionX, Settings::HUD::c_hudControlsHeadingPositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "Controls:";

	//Control Up
	setPositionXY(Settings::HUD::c_hudControlUpPositionX, Settings::HUD::c_hudControlUpPositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "W-Up ";

	//Control Down
	setPositionXY(Settings::HUD::c_hudControlDownPositionX, Settings::HUD::c_hudControlDownPositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "S-Down ";

	//Control Left
	setPositionXY(Settings::HUD::c_hudControlLeftPositionX, Settings::HUD::c_hudControlLeftPositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "A-Left ";

	//Control Right
	setPositionXY(Settings::HUD::c_hudControlRightPositionX, Settings::HUD::c_hudControlRightPositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "D-Right ";

	//Control Exit
	setPositionXY(Settings::HUD::c_hudControlExitPositionX, Settings::HUD::c_hudControlExitPositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "X-Exit ";
}

void UserInterfaceHUD::displayHUDValues()
{
	//Set the position of the snake position hud and display the text that will be constantly updated
	setPositionXY(Settings::HUD::c_hudSnakePositionX, Settings::HUD::c_hudSnakePositionY);
	moveToXYPosition(getPositionXYReadOnly());

	if (m_currentSnakePositionY < 10)
	{
		std::cout << "XY: ( " << m_currentSnakePositionX << ",  " << m_currentSnakePositionY << " )";
	}
	else
	{
		std::cout << "XY: ( " << m_currentSnakePositionX << ", " << m_currentSnakePositionY << " )";
	}

	//Set the position of the score hud and display the text that will be constantly updated
	setPositionXY(Settings::HUD::c_hudScorePositionX, Settings::HUD::c_hudScorePositionY);
	moveToXYPosition(getPositionXYReadOnly());
	std::cout << "Score: " << m_score;
}
