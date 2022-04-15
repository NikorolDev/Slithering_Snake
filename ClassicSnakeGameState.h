#ifndef CLASSICSNAKEGAMESTATE_H
#define CLASSICSNAKEGAMESTATE_H

#include "Fruit.h"
#include "GameState.h"
#include "MapBuilder.h"
#include "Snake.h"
#include "State.h"
#include "UserInterfaceHUD.h"

//---------------------------------------------------------------------------------------------------------------------
// Class Name			: ClassicSnakeGameState
// Classes Inherited	: State
// Purpose				: To have a state where the player can play the classical snake game that is just a plain map
//---------------------------------------------------------------------------------------------------------------------
class ClassicSnakeGameState : public State
{
private:
#pragma region private variables
	bool m_hasFruitRendered; //This checks if the fruit has rendered
	bool m_isStillAlive; //This checks if the snake is still alive

	char m_fruitCharacter; //The character that will represent the fruit
	char m_snakeCharacter; //The character that will represent the snake

	int m_startingSnakePositionX; //This is the starting position of the snake on X
	int m_startingSnakePositionY; //This is the starting position of the snake on Y
	int m_score; //This is the score counter to be displayed on the HUD area
	int m_tailSegmentOnStart; //The amount tail segments on start
	int m_tailSegmentAmount; //The amount of current tail segments

	Fruit m_fruit; //This will generate the fruit on the map as a single object
	MapBuilder m_map; //This will draw the map on the screen once
	Snake m_snake; //This is the snake that the player will control
	UserInterfaceHUD* m_hud; //This is the HUD that will display the scores, position and controls

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise()
	// Parameters		: None
	// Purpose			: To initialise this game mode state by initialising the values and construct objects needed
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: checkCollisionOfFruit()
	// Parameters		: None
	// Purpose			: To check the collision of the fruit with the snake and randomise position of the next one
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void checkCollisionOfFruit();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: checkCollisionOfFruit()
	// Parameters		: None
	// Purpose			: To check the collision of the walls and with snake that will end the game
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void checkCollisionOfWalls();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: checkCollisionOfFruit()
	// Parameters		: None
	// Purpose			: A generic function to check if the will end
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void gameOverChecks();

#pragma endregion

public:
#pragma region constructors and destructor
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: ClassicSnakeGameState()
	// Parameters		: None
	// Notes			: To create this game mode by constructing all of the classes and initialising the values and 
	//					,	classes
	//---------------------------------------------------------------------------------------------------------------------
	ClassicSnakeGameState();

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: ClassicSnakeGameState()
	// Parameters		: None
	// Notes			: This destructor will be a default destructor that will destruct itself as no pointers are 
	//					,	used
	//---------------------------------------------------------------------------------------------------------------------
	~ClassicSnakeGameState();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: onEntry(GameState* gameState) override
	// Parameters		: GameState*
	// Purpose			: This will create the game mode when the entering this state
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void onEntry(GameState* gameState) override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: update(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: Whilst the player will be in the classic game state it will update the necessary objects
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void update(GameState* gameState) override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: render(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: This will render all of the necessary objects continuously
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render(GameState* gameState) override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: onExit(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: This will clear the classic game mode and enter the next state
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void onExit(GameState* gameState) override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: getStateInstance()
	// Parameters		: none
	// Purpose			: This is a singleton that will get an instance of the state class
	// Returns			: Returns an instance of this state
	//--------------------------------------------------------------------------------------------------------------------
	static State& getStateInstance();

#pragma endregion
};

#endif // !CLASSICSNAKEGAMESTATE_H
