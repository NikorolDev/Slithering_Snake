#ifndef GAMESTATE_H
#define GAMESTATE_H

//Forward class declaration of State to resolve, circular includes and to set pointers of GameSates
class State;

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: GameState
// Classes Inherited	: none
// Purpose				: To handle the current state by switching between states and to update and render the current
//						,	state 
//-------------------------------------------------------------------------------------------------------------------------
class GameState
{
private:
#pragma region private variables
	bool m_hasGameExited;

	//This State class pointer will be used to set our current state of the game
	State* m_currentState; 

#pragma endregion

public:
#pragma region Constructors and Deconstructors
	//---------------------------------------------------------------------------------------------------------------------
	// Constructor		: GameState()
	// Parameters		: none
	// Notes			: Initialises the current state of our game to the first state, which would be the main menu
	//---------------------------------------------------------------------------------------------------------------------
	GameState();

	//---------------------------------------------------------------------------------------------------------------------
	// Deconstructor	: GameState()
	// Parameters		: none
	// Notes			: This will delete the State pointer, which is m_currentState
	//---------------------------------------------------------------------------------------------------------------------
	~GameState();

#pragma endregion
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: update()
	// Parameters		: none
	// Purpose			: This update function will update the current state, by using "this" keyword
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	void update();

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: render()
	// Parameters		: none
	// Purpose			: This redner function will render the current state, by using "this" keyword
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	void render();

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: setState(State& newState)
	// Parameters		: State& newState
	// Purpose			: This function will change the state in our game and set it as current one and will set the 
	//					,	initialiser boolean to true once the state has been initialised
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setState(State& newState);

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: getCurrentState
	// Parameters		: none
	// Purpose			: This function will get the current state that the player is in
	// Returns			: State* m_currentState
	// Usage Example	: 
	//---------------------------------------------------------------------------------------------------------------------
	State* getCurrentState() const;

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: setHasExitedGame(bool hasExitedGame)
	// Parameters		: hasExitedGame - sets the boolean that runs the game
	// Purpose			: To set the boolean which will exit the game
	// Returns			: Nothing
	//---------------------------------------------------------------------------------------------------------------------
	void setHasExitedGame(bool hasExitedGame);

	//---------------------------------------------------------------------------------------------------------------------
	// Function name	: getHasExitedGame()
	// Parameters		: None
	// Purpose			: To get the boolean that checks if the game will exit or not
	// Returns			: Returns the boolean that will exit the game or not
	//---------------------------------------------------------------------------------------------------------------------
	bool getHasExitedGame();
};

#endif // !GAMESTATE_H
