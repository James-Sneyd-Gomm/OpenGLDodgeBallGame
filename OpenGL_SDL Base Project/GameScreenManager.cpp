#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"
#include "GameScreenGameOver.h"
#include "MenuScreen.h"
#include "GameScreenVictory.h"
#include "GameScreenLevel2.h"
#include "GameScreenTutorial.h"

//--------------------------------------------------------------------------------------------------
GameScreenManager* GameScreenManager::mInstance;

GameScreenManager::GameScreenManager(SCREENS startScreen)
{
	mCurrentScreen = NULL;
	mCurrentScreen = 0;

	//Ensure the first screen is set up.
	ChangeScreen(startScreen);
}

//--------------------------------------------------------------------------------------------------

GameScreenManager::~GameScreenManager()
{
	delete mCurrentScreen;
	mCurrentScreen = NULL;
}

//--------------------------------------------------------------------------------------------------

void GameScreenManager::Render()
{
	mCurrentScreen->Render();
}

//--------------------------------------------------------------------------------------------------

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	mCurrentScreen->Update(deltaTime, e);
}

//--------------------------------------------------------------------------------------------------

void GameScreenManager::ChangeScreen(SCREENS newScreen)
{
	//Clear up the old screen.
	if(mCurrentScreen != NULL)
	{
		delete mCurrentScreen;
	}

	GameScreenLevel1* tempScreen1;
	GameScreenGameOver* tempScreenGO;
	MenuScreen* tempScreenMenu;
	GameScreenVictory* tempScreenVictory;
	GameScreenLevel2* tempScreen2;
	GameScreenTutorial* tempScreenTutorial;

	//Initialise the new screen.
	switch(newScreen)
	{
		case SCREEN_INTRO:
		break;

		case SCREEN_MENU:
			tempScreenMenu = new MenuScreen();
			mCurrentScreen = (GameScreen*)tempScreenMenu;
			tempScreenMenu = NULL;
		break;

		case SCREEN_LEVEL1:
			tempScreen1 = new GameScreenLevel1();
			mCurrentScreen = (GameScreen*)tempScreen1;
			mCurrentLevel = SCREEN_LEVEL1;
			tempScreen1 = NULL;
		break;

		case SCREEN_LEVEL2:
			tempScreen2 = new GameScreenLevel2();
			mCurrentScreen = (GameScreen*)tempScreen2;
			mCurrentLevel = SCREEN_LEVEL2;
			tempScreen2 = NULL;
			break;
		
		case SCREEN_GAMEOVER:
			tempScreenGO = new GameScreenGameOver();
			mCurrentScreen = (GameScreen*)tempScreenGO;
			tempScreenGO = NULL;
		break;

		case SCREEN_TUTORIAL:
			tempScreenTutorial = new GameScreenTutorial();
			mCurrentScreen = (GameScreen*)tempScreenTutorial;
			tempScreenTutorial = NULL;
			break;
		
		case SCREEN_HIGHSCORES:
			tempScreenVictory = new GameScreenVictory();
			mCurrentScreen = (GameScreen*)tempScreenVictory;
			tempScreenVictory = NULL;
		break;
		
		default:
		break;
	}
}

//--------------------------------------------------------------------------------------------------