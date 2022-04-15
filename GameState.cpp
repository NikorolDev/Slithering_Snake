#include "GameState.h"
#include "MainMenuState.h"

GameState::GameState()
//Initial values before the constructor gets called
	: m_hasGameExited	(false)
	, m_currentState	(&MainMenuState::getStateInstance())
{
	//Enter the current state
	m_currentState->onEntry(this);
}

GameState::~GameState()
{
}

void GameState::update()
{
	//Update the current state, using "this" keyword
	m_currentState->update(this);
}

void GameState::render()
{
	//Render the current state, using "this" keyword
	m_currentState->render(this);
}

void GameState::setState(State& newState)
{
	m_currentState->onExit(this); //Exit the current state
	m_currentState = &newState; //Set new state as current state
	m_currentState->onEntry(this); //Enter the new current state
}

State* GameState::getCurrentState() const { return m_currentState; }

void GameState::setHasExitedGame(bool hasExitedGame)
{
	m_hasGameExited = hasExitedGame;
}

bool GameState::getHasExitedGame()
{
	return m_hasGameExited;
}
