#include "GameScreenGameOver.h"
#include "GameScreenManager.h"
#include "../gl/glut.h"
#include "Constants.h"
#include "Commons.h"

using namespace::std;

//--------------------------------------------------------------------------------------------------

GameScreenGameOver::GameScreenGameOver() : GameScreen()
{
	glDisable(GL_LIGHTING);
	mInteractiveText.push_back("Return to Main Menu");
	mInteractiveText.push_back("Quit Game");

	if (mInteractiveText.size() != 0)
	{
		selected = MENU_RETURN;
	}
	mStaticText.push_back("You Lose!");
	mStaticText.push_back("Return to main menu or exit game.");
}

//--------------------------------------------------------------------------------------------------

GameScreenGameOver::~GameScreenGameOver()
{

}

void GameScreenGameOver::Render()
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

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}


void GameScreenGameOver::Update(float deltaTime, SDL_Event e)
{
	HandleInput(e);
}

void GameScreenGameOver::HandleInput(SDL_Event e)
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

void GameScreenGameOver::HandleSelectedItem()
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
void GameScreenGameOver::outputLine(float x, float y, string text)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < text.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

}

