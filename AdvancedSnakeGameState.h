#ifndef ADVANCEDSNAKEGAMESTATE_H
#define ADVANCEDSNAKEGAMESTATE_H

#include "EnumMapOptions.h"
#include "Fruit.h"
#include "GameState.h"
#include "MapBuilder.h"
#include "MenuButton.h"
#include "MenuPointer.h"
#include "Snake.h"
#include "State.h"
#include "UserInterfaceHUD.h"

//---------------------------------------------------------------------------------------------------------------------
// Class Name			: ClassicSnakeGameState
// Classes Inherited	: State
// Purpose				: To have a state where the player can play snake on different maps
//---------------------------------------------------------------------------------------------------------------------
class AdvancedSnakeGameState : public State
{
private:
#pragma region private variables
	bool m_hasFruitRendered; //This checks if the fruit has rendered
	bool m_hasMapSwitched; //This checks if map has been switched to render a different map in selection
	bool m_isInSelection; //This checks if the player is in selection
	bool m_isStillAlive; //This checks if the snake is still alive

	char m_fruitCharacter; //The character that will represent the fruit
	char m_pointerCharacter; //The character that will represent the pointer
	char m_snakeCharacter; //The character that will represent the snake

	int m_buttonPositionX; //The button position on the X
	int m_buttonStartingPositionY; //The starting button position on the Y
	int m_numberOfButtons; //The amount of buttons to be rendered
	int m_pointerPositionX; //The pointer position on the X
	int m_pointerPositionY; //The pointer position on the Y
	int m_startingSnakePositionX; //This is the starting position of the snake on X
	int m_startingSnakePositionY; //This is the starting position of the snake on Y
	int m_score; //This is the score counter to be displayed on the HUD area
	int m_tailSegmentOnStart; //The amount tail segments on start
	int m_tailSegmentAmount; //The amount of current tail segments

	EnumMapOptions m_enumMapOptions; //This will set the map option that the player has picked to play
	Fruit m_fruit; //This will generate the fruit on the map as a single object
	MapBuilder m_map; //This will draw the map on the screen once
	MenuPointer m_mapPointer; //The pointer that will be moving next to the buttons
	Snake m_snake; //This is the snake that the player will control
	UserInterfaceHUD m_hud; //This is the HUD that will display the scores, position and controls
	
	MenuButton* m_pMenuButtons; //The menu pointer will be used as an array of pointers to make buttons

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
	// Function name	: initialiseSelectMapMenu()
	// Parameters		: None
	// Purpose			: To initialise this game mode state by initialising the values and construct objects needed
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialiseSelectMapMenu();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: checkCollisionOfFruit()
	// Parameters		: None
	// Purpose			: To check the collision of the fruit with the snake and randomise position of the next one and	
	//					,	proofing that it won't spawn on walls
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

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: switchingMaps()
	// Parameters		: None
	// Purpose			: This will switch between maps and render it for preview
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void switchingMaps();

#pragma endregion

public:
#pragma region constructors and destructor
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: AdvancedSnakeGameState()
	// Parameters		: None
	// Notes			: To create this game mode by constructing all of the classes and initialising the values and 
	//					,	classes
	//---------------------------------------------------------------------------------------------------------------------
	AdvancedSnakeGameState();

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: AdvancedSnakeGameState()
	// Parameters		: None
	// Notes			: This destructor will safely delete the menu buttons 
	//---------------------------------------------------------------------------------------------------------------------
	~AdvancedSnakeGameState();

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

#endif // !ADVANCEDSNAKEGAMESTATE_H
