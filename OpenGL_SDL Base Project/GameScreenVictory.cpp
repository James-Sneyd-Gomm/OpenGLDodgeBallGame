#include "GameScreenVictory.h"
#include "GameScreenManager.h"
#include "../gl/glut.h"
#include "Constants.h"
#include "Commons.h"

using namespace::std;

//--------------------------------------------------------------------------------------------------

GameScreenVictory::GameScreenVictory() : GameScreen()
{
	glDisable(GL_LIGHTING);
	mInteractiveText.push_back("Return to Main Menu");
	mInteractiveText.push_back("Quit Game");

	if (mInteractiveText.size() != 0)
	{
		selected = MENU_RETURN;
	}
	mStaticText.push_back("You WIN!");
	mStaticText.push_back("Return to main menu or exit game.");
	mStaticText.push_back("Why not try the other level?");

	mScore = GameScreenManager::Instance()->GetScore();
}

//--------------------------------------------------------------------------------------------------

GameScreenVictory::~GameScreenVictory()
{

}

void GameScreenVictory::Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < mInteractiveText.size(); i++)
	{
		if (i == selected)
		{
			glColor3f(1.0f, 0.4f, 0.0f);
		}
		else
		{
			glColor3f(0.0f, 0.0f, 0.0f);
		}

		outputLine(30, 40 - 5 * i, mInteractiveText[i]);
	}

	for (int j = 0; j < mStaticText.size(); j++)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		outputLine(20, 80 - 5 * j, mStaticText[j]);
	}
	outputLine(20, 50, "Score:");
	outputLine(30, 50, mScore);
	outputLine(40, 50, "Seconds");
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}


void GameScreenVictory::Update(float deltaTime, SDL_Event e)
{
	HandleInput(e);
}

void GameScreenVictory::HandleInput(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			if (selected > 0)
			{
				selected = selected - 1;
			}
			break;

		case SDLK_DOWN:
			if (selected < mInteractiveText.size() - 1)
			{
				selected++;
			}
			break;

		case SDLK_RETURN:
			HandleSelectedItem();
			break;
		}
	}
}

void GameScreenVictory::HandleSelectedItem()
{
	switch (selected)
	{
	case -1:
		break;

	case 0:
		GameScreenManager::Instance()->ChangeScreen(SCREEN_MENU);
		break;

	case 1:
		SDL_Event quit;
		quit.type = SDL_QUIT;
		SDL_PushEvent(&quit);
		break;


	}
}
void GameScreenVictory::outputLine(float x, float y, string text)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < text.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

}

