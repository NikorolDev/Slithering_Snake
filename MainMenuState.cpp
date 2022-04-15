#include <Windows.h>

#include "AdvancedSnakeGameState.h"
#include "ClassicSnakeGameState.h"
#include "Helpers.h"
#include "MainMenuState.h"

MainMenuState::MainMenuState()
//Initial values before the constructor gets called
	: m_hasGameExited			(false)
	, m_pointerCharacter		(Settings::Characters::c_pointerCharacter)
	, m_buttonPositionX			(13)
	, m_buttonStartingPositionY	(14)
	, m_numberOfButtons			(3)
	, m_pointerPositionX		(11)
	, m_pointerPositionY		(14)
{
	//Initialise main menu
	initialise();
}

MainMenuState::~MainMenuState()
{
	//Delete the menu buttons pointer
	SAFE_DELETE_ARRAY(m_pMenuButtons);
}

void MainMenuState::onEntry(GameState* gameSate)
{
	//Render the game title and initalise the main menu
	m_gameTitle.render();
	initialise();

	//Loop through the menu button pointer to render them on the screen
	for (int buttonCounter = 0; buttonCounter < m_numberOfButtons; ++buttonCounter)
	{
		m_pMenuButtons[buttonCounter].render();
	}
}

void MainMenuState::update(GameState* gameSate)
{
	//Update the menu pointer, which is mainly movement and check if a game mode has been selected
	m_menuPointer.update();
	selectGameMode();

	//Based on the selected game mode it will change state to that game mode
	switch (m_enumGameStates)
	{
		case EnumGameStates::ClassicSnake: //Classic game mode
		{
			gameSate->setState(ClassicSnakeGameState::getStateInstance());
			break;
		}

		case EnumGameStates::AdvancedSnake: //Advanced game mode, which has a map selector
		{
			gameSate->setState(AdvancedSnakeGameState::getStateInstance());
			break;
		}

		case EnumGameStates::Quit: //Exit game
		{
			gameSate->setHasExitedGame(true);
			break;
		}
	}
}

void MainMenuState::render(GameState* gameState)
{
	//render the menu pointer as it is the only object being updated
	m_menuPointer.render();
}

void MainMenuState::onExit(GameState* gameSate)
{
	//Delete the menu buttons pointer and clear screen
	SAFE_DELETE_ARRAY(m_pMenuButtons);
	system("CLS");
}

State& MainMenuState::getStateInstance()
{
	//Create a singleton of this state by defining it as a static and return the menu state
	static MainMenuState stateInstance;
	return stateInstance;
}

void MainMenuState::initialise()
{
	//Set the state to the main menu so that it doesn't go the game mode previously chosen
	m_enumGameStates = EnumGameStates::MainMenu;

	//Create an int of button position Y as it will be updated to create each button and make new buttons based on the amount declared
	int buttonPositionY = m_buttonStartingPositionY;
	m_pMenuButtons = new MenuButton[m_numberOfButtons];

	//Set pointer position and using the second constructor will create the desired pointer
	m_menuPointer.setPositionXY(m_pointerPositionX, m_pointerPositionY);
	m_menuPointer = MenuPointer(m_pointerCharacter, m_menuPointer.getPositionXYReadOnly());

	//Set pointer minimum selection position so that it go above the first button
	m_menuPointer.setMinSelectionPositionY(buttonPositionY);

	//Loop through each button and create one that will have their own unique text and position
	for (int buttonCounter = 0; buttonCounter < m_numberOfButtons; buttonCounter++)
	{
		//First set position, to be using local variable of button position Y as it will be incremented each loop
		m_pMenuButtons[buttonCounter].setPositionXY(m_buttonPositionX, buttonPositionY);

		//Based on the button counter it will create each button in order
		switch (buttonCounter)
		{
			case 0: //Classic Snake button
			{
				m_pMenuButtons[buttonCounter] = MenuButton("Classic Snake", m_pMenuButtons[buttonCounter].getPositionXYReadOnly());
				break;
			}

			case 1: //Advanced Snake button
			{
				m_pMenuButtons[buttonCounter] = MenuButton("Advanced Snake", m_pMenuButtons[buttonCounter].getPositionXYReadOnly());
				break;
			}

			case 2: //Quit button
			{
				m_pMenuButtons[buttonCounter] = MenuButton("Quit", m_pMenuButtons[buttonCounter].getPositionXYReadOnly());
				break;
			}
		}
		//Increment button position Y to move the next button down
		buttonPositionY++;
	}
	//Set the maximum selection position so that the pointer doesn't go below the last button
	m_menuPointer.setMaxSelectionPositionY(buttonPositionY);

	std::cout << "Controls:\n W-Up\n S-Down\n E-Select";
}

void MainMenuState::selectGameMode()
{
	//Check if the pointer has selected game mode
	if (m_menuPointer.getHasSelected() == true)
	{
		//Based on the pointer position it will select game state
		switch (m_menuPointer.getPositionY())
		{
			case 14: //Classic snake game mode state
			{
				m_enumGameStates = EnumGameStates::ClassicSnake;
				break;
			}

			case 15: //Advanced snake game mode state
			{
				m_enumGameStates = EnumGameStates::AdvancedSnake;
				break;
			}

			case 16: //Quit state
			{
				m_enumGameStates = EnumGameStates::Quit;
				break;
			}
		}
	}
}

