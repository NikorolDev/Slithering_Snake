#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "EnumGameStates.h"
#include "GameTitleElement.h"
#include "GameState.h"
#include "MenuButton.h"
#include "MenuPointer.h"
#include "State.h"

//---------------------------------------------------------------------------------------------------------------------
// Class Name			: MainMenuState
// Classes Inherited	: State
// Purpose				: To have a state where the player will the main menu and interact with it 
//						,	to select game modes for example 
//---------------------------------------------------------------------------------------------------------------------
class MainMenuState : public State
{
private:
#pragma region private variables
	bool m_hasGameExited; //This checks if the game has exited which will exit the whole game
	
	char m_pointerCharacter; //The character that will represent the pointer

	int m_buttonPositionX; //This is the position of where the buttons will be placed on the X
	int m_buttonStartingPositionY; //This is the starting position of the buttons on the Y
	int m_numberOfButtons; //The number of buttons to be rendered on the main menu
	int m_pointerPositionX; //The position of the pointer on the X
	int m_pointerPositionY; //The position of the pointer on the Y

	EnumGameStates m_enumGameStates; //The game states that will be used to change states with in the game from main menu
	GameTitleElement m_gameTitle; //The game title that will be rendered first
	MenuPointer m_menuPointer; //The pointer that will be moving next to the buttons

	MenuButton* m_pMenuButtons; //The menu pointer will be used as an array of pointers to make buttons

#pragma endregion

#pragma region private functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: initialise()
	// Parameters		: None
	// Purpose			: To initialise the main menu by creating buttons and the pointer as the rest will be constructed 
	//					,	through the default constructor
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void initialise();

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: selectGameMode()
	// Parameters		: None
	// Purpose			: This will select the game mode based on the pointers position, once it's selected
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void selectGameMode();

#pragma endregion

public:
#pragma region constructors and destructor
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor name	: MainMenuState()
	// Parameters		: None
	// Notes			: To create the main menu by constructing all of the classes and initialise the values and classes
	//---------------------------------------------------------------------------------------------------------------------
	MainMenuState();

	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: MainMenuState()
	// Parameters		: None
	// Notes			: This destructor will delete the menu pointer to clean up the heap
	//---------------------------------------------------------------------------------------------------------------------
	~MainMenuState();

#pragma endregion

#pragma region public functions
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: onEntry(GameState* gameState) override
	// Parameters		: GameState*
	// Purpose			: This will create the main menu when the entering this state
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void onEntry(GameState* gameState) override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: update(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: Whilst the player will be in the main menu it will update the anything that the player interacts 
	//					,	with
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void update(GameState* gameSate) override;

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
	// Purpose			: This will clear the main menu and safely delete the menu pointers and enter the next state
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void onExit(GameState* gameState) override;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: getStateInstance()
	// Parameters		: none
	// Purpose			: This is a singleton that will get an instance of the state class
	// Returns			: Returns an instance of this state
	//---------------------------------------------------------------------------------------------------------------------
	static State& getStateInstance();

#pragma endregion
};

#endif // !MAINMENUSTATE_H
