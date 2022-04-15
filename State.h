#ifndef STATE_H
#define STATE_H

//Forward class declaration of GameState to resolve, circular includes and to set pointers of GameSates
class GameState;

//-------------------------------------------------------------------------------------------------------------------------
// Class Name			: State
// Classes Inherited	: none
// Purpose				: To create states within the game so it is easy to handle them in the 
//						,   game.
//-------------------------------------------------------------------------------------------------------------------------
class State
{
public:
	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: onEntry(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: To do certain processes to enter a state. This will be overridden per state
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void onEntry(GameState* gameState) = 0;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: update(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: To update anything within the state. This will be overridden per state
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void update(GameState* gameState) = 0;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: render(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: To render anything within the state. This will be overridden per state
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void render(GameState* gameState) = 0;

	//---------------------------------------------------------------------------------------------------------------------
	// Function Name	: onExit(GameState* gameState)
	// Parameters		: GameState*
	// Purpose			: To do certain processes to exit a state. This will be overridden per state
	// Returns			: nothing
	//---------------------------------------------------------------------------------------------------------------------
	virtual void onExit(GameState* gameState) = 0;
	
	//---------------------------------------------------------------------------------------------------------------------
	// Destructor name	: Snake()
	// Parameters		: None
	// Notes			: This virtual destructor will destruct every derived class of this one.
	//---------------------------------------------------------------------------------------------------------------------
	virtual ~State() {};
};

#endif // !STATE_H
