#include <tchar.h>
#include <Windows.h>

#include "ClassicSnakeGameState.h"
#include "Helpers.h"
#include "MainMenuState.h"

ClassicSnakeGameState::ClassicSnakeGameState()
//Initial values before the constructor gets called that will not change during this state
	: m_fruitCharacter			(Settings::Characters::c_fruitCharacter)
	, m_snakeCharacter			(Settings::Characters::c_snakeCharacter)
	, m_startingSnakePositionX	(Settings::Positions::c_snakeSpawnPositionX)
	, m_startingSnakePositionY	(Settings::Positions::c_snakeSpawnPositionY)
	, m_tailSegmentOnStart		(0)
{
	//Initialise values and classes
	initialise();
}

ClassicSnakeGameState::~ClassicSnakeGameState()
{
	SAFE_DELETE(m_hud);
}

void ClassicSnakeGameState::onEntry(GameState* gameSate)
{
	//Initialise values and classes and set the snake is alive to true as the game has started playing
	initialise();
	m_isStillAlive = true;

	//Update everything so everything is set up, for example the fruit position and snake's position
	update(gameSate);	
	
	//Render the map and hud
	m_map.drawMap();
	m_hud->render();
}

void ClassicSnakeGameState::update(GameState* gameSate)
{
	//If the snake is still alive 
	if (m_isStillAlive == true)
	{
		//Update the snake and the HUD with the passed through snake position and score
		m_snake.update();
		m_hud->update(m_snake.getPositionXYReadOnly(), m_score);

		//Check the collision with the fruit
		checkCollisionOfFruit();

		//Check if the game is over
		gameOverChecks();
	}
	//If the snake is not alive, change to the the main menu state
	else
	{
		gameSate->setState(MainMenuState::getStateInstance());
	}
	
}

void ClassicSnakeGameState::render(GameState* gameState)
{
	//if the snake is still alive
	if (m_isStillAlive == true)
	{
		//render the fruit, snake and change the colour back to the default console colour
		m_fruit.render();
		m_snake.render();
		colourCharacter(Settings::Colours::c_defaultConsoleColour);
	}
}

void ClassicSnakeGameState::onExit(GameState* gameSate)
{
	//Clear the screen and everything will be destructed after
	system("CLS");
}

State& ClassicSnakeGameState::getStateInstance()
{
	//Create a singleton of this state by defining it as a static and return the classic game mode state
	static ClassicSnakeGameState stateInstance;
	return stateInstance;
}

void ClassicSnakeGameState::initialise()
{
	//Initialise/ re-initialise these values
	m_hasFruitRendered				= false;
	m_isStillAlive					= false;
	m_score							= 0;
	m_tailSegmentAmount				= m_tailSegmentOnStart;

	m_map = MapBuilder(1); //Set the map to the classic plain map
	m_fruit = Fruit(m_fruitCharacter, 0, 0); //Set the fruit initial 

	//Set the snake using second constructor, which will set the character and the positions
	m_snake = Snake(m_snakeCharacter, m_startingSnakePositionX, m_startingSnakePositionY, m_tailSegmentOnStart);

	m_hud = new UserInterfaceHUD();
}

void ClassicSnakeGameState::checkCollisionOfFruit()
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
			PlaySound(_T("Audio/Score.wav"), NULL, SND_ASYNC);
			m_score += 10;
		}
	}

	//If the fruit has not been rendered
	if (m_hasFruitRendered == false)
	{
		//Set a random position of the fruit and set the fruit is rendered. This is the default function overload
		m_fruit.randomiseFruitPosition();
		m_hasFruitRendered = true;
	}
}

void ClassicSnakeGameState::checkCollisionOfWalls()
{
	//To check if the snake has hit the wall. Loop through the wall rows
	for (int mapRowCounter = 0; mapRowCounter < Settings::Map::c_mapMaxHeight; ++mapRowCounter)
	{
		//Loop through the wall columns
		for (int mapColumnCounter = 0; mapColumnCounter < Settings::Map::c_mapMaxWidth; ++mapColumnCounter)
		{
			//Get the element value of the map and check if it's is 1. That represents the wall
			if (m_map.getMapWall(mapRowCounter, mapColumnCounter) == 1)
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

void ClassicSnakeGameState::gameOverChecks()
{
	//If the player exited the game it will set the snake to be dead
	if (m_snake.getHasGameModeExited() == true)
	{
		m_isStillAlive = false;
	}

	//Check the collision with walls
	checkCollisionOfWalls();
}
