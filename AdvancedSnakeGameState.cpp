#include <tchar.h>
#include <Windows.h>

#include "AdvancedSnakeGameState.h"
#include "Helpers.h"
#include "MainMenuState.h"
#include "Settings.h"

AdvancedSnakeGameState::AdvancedSnakeGameState()
//Initial values before the constructor gets called that will not change during this state
	: m_fruitCharacter			(Settings::Characters::c_fruitCharacter)
	, m_pointerCharacter		(Settings::Characters::c_pointerCharacter)
	, m_snakeCharacter			(Settings::Characters::c_snakeCharacter)
	, m_buttonPositionX			(9)
	, m_buttonStartingPositionY (30)
	, m_numberOfButtons			(4)
	, m_pointerPositionX		(7)
	, m_startingSnakePositionX	(Settings::Positions::c_snakeSpawnPositionX)
	, m_startingSnakePositionY	(Settings::Positions::c_snakeSpawnPositionY)
	, m_tailSegmentOnStart		(0)
{
	//Initialise values and classes
	initialise();
}

AdvancedSnakeGameState::~AdvancedSnakeGameState()
{
	SAFE_DELETE_ARRAY(m_pMenuButtons);
}

void AdvancedSnakeGameState::onEntry(GameState* gameState)
{
	//Initialise values and classes
	initialise();
	
	//Render the buttons as the player starts off in the selection menu
	for (int buttonCounter = 0; buttonCounter < m_numberOfButtons; ++buttonCounter)
	{
		m_pMenuButtons[buttonCounter].render();
	}
}

void AdvancedSnakeGameState::update(GameState* gameState)
{
	//If the in selection menu
	if (m_isInSelection == true)
	{
		//Update the pointer and check if the map has switched
		m_mapPointer.update();
		switchingMaps();

		//Check if the player has selected map
		if (m_mapPointer.getHasSelected() == true)
		{
			//Based on the options
			switch (m_enumMapOptions)
			{
				case EnumMapOptions::Back: //If the player selected to go back then, it will send the player to the main menu
				{
					gameState->setState(MainMenuState::getStateInstance());
					break;
				}

				default: //Otherwise for all maps it will set the selected map
				{
					//Clear the screen
					system("CLS");

					//Render the map and the hud
					m_map.drawMap();
					m_hud.render();

					//Set the bools that player is not in selection and snake is alive
					m_isInSelection = false;
					m_isStillAlive = true;
				}
			}
		}
	}

	//If the snake is alive not in selection. This is to stop the code going to the other statement
	if (m_isStillAlive == true && m_isInSelection == false)
	{
		//Update the snake and the HUD using the passed through values
		m_snake.update();
		m_hud.update(m_snake.getPositionXYReadOnly(), m_score);

		//Check the collision with the fruit
		checkCollisionOfFruit();

		//Check if the game is over
		gameOverChecks();
	}
	//If the snake is not alive and is not in selection it will load the main menu
	else if(m_isStillAlive == false && m_isInSelection == false)
	{
		gameState->setState(MainMenuState::getStateInstance());
	}
}

void AdvancedSnakeGameState::render(GameState* gameState)
{
	//If in Selection mode
	if (m_isInSelection == true)
	{
		//If pointer has moved, it will draw a different map and set the map switch to false
		if (m_hasMapSwitched == true)
		{
			m_map.drawMap();
			m_hasMapSwitched = false;
		}

		//Render the pointer
		m_mapPointer.render();
	}

	//If the snake is alive, so in game
	if (m_isStillAlive == true)
	{
		//Render the fruit and the snake and set the colour back to default
		m_fruit.render();
		m_snake.render();
		colourCharacter(Settings::Colours::c_defaultConsoleColour);
	}
}

void AdvancedSnakeGameState::onExit(GameState* gameState)
{
	SAFE_DELETE_ARRAY(m_pMenuButtons);

	//Clear the screen on exit
	system("CLS");
}

State& AdvancedSnakeGameState::getStateInstance()
{
	static AdvancedSnakeGameState stateInstance;
	return stateInstance;
}

void AdvancedSnakeGameState::initialise()
{
	//Initialise/ re-initialise these values
	m_hasFruitRendered				= false;
	m_isStillAlive					= false;
	m_hasMapSwitched				= true;
	m_isInSelection					= true;
	m_pointerPositionY				= 30;
	m_score							= 0;
	m_tailSegmentAmount				= m_tailSegmentOnStart;
	m_enumMapOptions				= EnumMapOptions::NumberOfMaps;

	//Initialise the select menu as it is the first thing the player will do
	initialiseSelectMapMenu();


	m_map = MapBuilder(2); //Set the map to the first selected on the options
	m_fruit = Fruit(m_fruitCharacter, 0, 0); //Set the fruit using the second constructor, which will set the character and positions

	//Set the snake using second constructor, which will set the character and the positions
	m_snake = Snake(m_snakeCharacter, m_startingSnakePositionX, m_startingSnakePositionY, m_tailSegmentOnStart);
}

void AdvancedSnakeGameState::initialiseSelectMapMenu()
{
	//Create an int of button position Y as it will be updated to create each button and make new buttons based on the amount declared
	int buttonPositionY = m_buttonStartingPositionY;
	m_pMenuButtons = new MenuButton[m_numberOfButtons];

	//Set pointer position and using the second constructor will create the desired pointer
	m_mapPointer.setPositionXY(m_pointerPositionX, m_pointerPositionY);
	m_mapPointer = MenuPointer('>', m_mapPointer.getPositionXYReadOnly());
	m_mapPointer.setMinSelectionPositionY(buttonPositionY);

	//Loop through each button and create one that will have their own unique text and position
	for (int buttonCounter = 0; buttonCounter < m_numberOfButtons; ++buttonCounter)
	{
		//First set position, to be using local variable of button position Y as it will be incremented each loop
		m_pMenuButtons[buttonCounter].setPositionXY(m_buttonPositionX, buttonPositionY);

		//Based on the button counter it will create each button in order
		switch (buttonCounter)
		{
			case 0: //Over The Hedges map button
			{
				m_pMenuButtons[buttonCounter] = MenuButton("Over The Hedges", m_pMenuButtons[buttonCounter].getPositionXYReadOnly());
				break;
			}

			case 1: //Two Rivers map button
			{
				m_pMenuButtons[buttonCounter] = MenuButton("Two Rivers", m_pMenuButtons[buttonCounter].getPositionXYReadOnly());
				break;
			}

			case 2: //The Woods map button
			{
				m_pMenuButtons[buttonCounter] = MenuButton("The Woods", m_pMenuButtons[buttonCounter].getPositionXYReadOnly());
				break;
			}

			case 3: //The back button
			{
				m_pMenuButtons[buttonCounter] = MenuButton("Back", m_pMenuButtons[buttonCounter].getPositionXYReadOnly());
				break;
			}
		}
		//Increment button position Y to move the next button down
		buttonPositionY++;
	}
	//Set the maximum selection position so that the pointer doesn't go below the last button
	m_mapPointer.setMaxSelectionPositionY(buttonPositionY);
}

void AdvancedSnakeGameState::checkCollisionOfFruit()
{
	//Check if the fruit has rendered
	if (m_hasFruitRendered == true)
	{
		//Check if the snake's position matches the fruit's position
		if (( m_snake.getPositionX() == m_fruit.getPositionX() ) && ( m_snake.getPositionY() == m_fruit.getPositionY() ))
		{
			//Unrender the fruit and set unredered as false so it will render when the next position is set
			m_fruit.unrender();			
			m_hasFruitRendered = false;

			//Increment the tail segment amount and set it to the snake, which will create another tail segment
			m_tailSegmentAmount++;
			m_snake.setNumberOfTailSegments(m_tailSegmentAmount);
			
			//Play sound and add 10 to the scores
			PlaySound(_T("Audio/Score.wav"), NULL, SND_APPLICATION);
			m_score += 10;
		}
	}

	//If the fruit has not been rendered. This will make sure the fruit will not spawn on the walls
	if (m_hasFruitRendered == false)
	{
		//Loop through the map rows 
		for (int mapRowCounter = 0; mapRowCounter < Settings::Map::c_mapMaxHeight; ++mapRowCounter)
		{
			//Loop through the wall columns
			for (int mapColumnCounter = 0; mapColumnCounter < Settings::Map::c_mapMaxWidth; ++mapColumnCounter)
			{
				//Randomise the fruit position, by passing through the wall counter and the wall identifier. This is the second overload function
				m_fruit.randomiseFruitPosition(mapRowCounter, mapColumnCounter, m_map.getMapWall(mapRowCounter, mapColumnCounter));
			}
		}
		//Set the fruit has rendered
		m_hasFruitRendered = true;
	}
}

void AdvancedSnakeGameState::checkCollisionOfWalls()
{
	//To check if the snake has hit the wall. Loop through the wall rows
	for (int mapRowCounter = 0; mapRowCounter < Settings::Map::c_mapMaxHeight; ++mapRowCounter)
	{
		//Loop through the wall columns
		for (int mapColumnCounter = 0; mapColumnCounter < Settings::Map::c_mapMaxWidth; ++mapColumnCounter)
		{
			//Get the element value of the map and check if it's is 1. That represents the wall
			if (m_map.getMapWall(mapRowCounter, mapColumnCounter) != 0)
			{
				//Check if the snake's position matches the wall's. That will trigger the game over
				if (m_snake.getPositionY() == mapRowCounter && m_snake.getPositionX() == mapColumnCounter)
				{
					m_isStillAlive = false;
				}
			}
		}
	}
}

void AdvancedSnakeGameState::gameOverChecks()
{
	//If the player exited the game it will set the snake to be dead
	if (m_snake.getHasGameModeExited() == true)
	{
		m_isStillAlive = false;
	}

	//Check the collision with walls
	checkCollisionOfWalls();
}

void AdvancedSnakeGameState::switchingMaps()
{
	//Based on the position of the pointer it will render the selected map for preview
	switch (m_mapPointer.getPositionY())
	{
		case 30: //Over The Hedges map
		{
			m_enumMapOptions = EnumMapOptions::OverTheHedges;
			m_map = MapBuilder(2);
			break;
		}

		case 31: //Two Rivers map
		{
			m_enumMapOptions = EnumMapOptions::TwoRivers;
			m_map = MapBuilder(3);
			break;
		}

		case 32: //The Woods map
		{
			m_enumMapOptions = EnumMapOptions::TheWoods;
			m_map = MapBuilder(4);
			break;
		}

		case 33: //Back to main menu
		{
			m_enumMapOptions = EnumMapOptions::Back;
			break;
		}
	}
	//The map has been switch which will rerender the map
	m_hasMapSwitched = true;
}
