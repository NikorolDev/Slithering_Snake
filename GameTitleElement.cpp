#include "FileReadingHeaders.h"
#include "GameTitleElement.h"
#include "Helpers.h"

GameTitleElement::GameTitleElement()
//Initialised values before being constructed
	: m_gameTitleHeight		(Settings::Title::c_titleHeight)
	, m_gameTitlePositionX	(Settings::Positions::c_middlePositionX - (Settings::Title::c_titleWidth/2))
	, m_gameTitlePositionY	(0)
	, m_gameTitleWidth		(Settings::Title::c_titleWidth)
{
	//Set the position of where title will be placed and set the map
	setPositionXY(m_gameTitlePositionX, m_gameTitlePositionY);
	setTitle();
}

GameTitleElement::~GameTitleElement()
{
}

void GameTitleElement::render()
{
	displayTitle();
}

void GameTitleElement::setTitle()
{
	//Create a string to hold the file address of where the game title file is located
	std::string titleGameFile = "csvFiles/GameTitle.csv";

	//Store the file in an ifstream variable
	std::ifstream csvFile(titleGameFile);

	//Loop through the row of the file first
	for (int titleRowCounter = 0; titleRowCounter < m_gameTitleHeight; ++titleRowCounter)
	{
		//Creating this string variable will get the whole line of the csv file
		std::string fileRow;
		std::getline(csvFile, fileRow);

		//Create an instance of the file row by creating a string stream and store it there
		std::stringstream stringStreamRow(fileRow);

		//Loop through the whole column to start adding values to the 2d array
		for (int titleColumnCounter = 0; titleColumnCounter < m_gameTitleWidth; ++titleColumnCounter)
		{
			std::string titleElement; //Create another string variable that will store each element of the csv file
			std::getline(stringStreamRow, titleElement, ','); //Using stringStreamRow, split the row with a ',' and store it in titleElement, which will hold that single value from the row

			//Create an instance of the element, which will add it to the 2d array
			std::stringstream converter(titleElement);
			converter >> m_gameTitleMatrix[titleRowCounter][titleColumnCounter];
		}
	}
}

void GameTitleElement::displayTitle()
{
	//We make a local variable of gameTitlePositionY as we will be updating the local variable to draw the title accordingly and not in one line
	int gameTitleRowPosition = m_gameTitlePositionY;

	//Loop through the rows of the title to start
	for (int titleRowCounter = 0; titleRowCounter < m_gameTitleHeight; ++titleRowCounter)
	{
		//On each row set the position of our row and move the cursor to that position.  
		//Every time we render the game title it will start from 0y, but then it will move to next line until all rows are completed
		setPositionXY(m_gameTitlePositionX, gameTitleRowPosition);
		moveToXYPosition(getPositionXYReadOnly());

		//Loop through each column which will be each element 
		for (int titleColumnCounter = 0; titleColumnCounter < m_gameTitleWidth; ++titleColumnCounter)
		{
			//Switch between each element in where the nested loop is in currently
			switch (m_gameTitleMatrix[titleRowCounter][titleColumnCounter])
			{
				case 0: //If element value is 0
				{
					//Set the colour of the text to be black with black background and output a character
					//Setting the colour will also prevent this character being coloured as a different colour set before
					colourCharacter(Settings::Colours::c_blackBox);
					std::cout << " ";
					break;
				}

				case 1: //If element value is 1
				{
					//Set the colour of the text to white with white background and output a character
					colourCharacter(Settings::Colours::c_whiteBox);
					std::cout << "O";
					break;
				}
			}

		}			

		//When the column has finished rendering move to next row
		gameTitleRowPosition++;
	}

	//When then whole game title has finished rendering set the colour to default and set position of cursor to 0,0
	colourCharacter(Settings::Colours::c_defaultConsoleColour);
	setPositionXY(Settings::Positions::c_consoleStartPositionX, Settings::Positions::c_consoleStartPositionY);
	moveToXYPosition(getPositionXYReadOnly());
}