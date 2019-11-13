#include "GameScreenTutorial.h"
#include "GameScreenManager.h"
#include "../gl/glut.h"
#include "Constants.h"
#include "Commons.h"

using namespace::std;

//--------------------------------------------------------------------------------------------------

GameScreenTutorial::GameScreenTutorial() : GameScreen()
{
	mInteractiveText.push_back("Return to Main Menu");

	if (mInteractiveText.size() != 0)
	{
		selected = MENU_RETURN;
	}
	mStaticText.push_back("Level 1!");
	mStaticText.push_back("Try to avoid all the dodgeballs while");
	mStaticText.push_back("getting to the other side of the court.");
	mStaticText.push_back("Use WASD to move, more then three hits and your out!");
	mStaticText.push_back("Level 2!");
	mStaticText.push_back("Oh No! The bullies have your cornered,");
	mStaticText.push_back("do your best to avoid them for as long as you can.");
	mStaticText.push_back("use A and D to move left and right, three hits and you lose!");
}

//--------------------------------------------------------------------------------------------------

GameScreenTutorial::~GameScreenTutorial()
{

}

void GameScreenTutorial::Render()
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


void GameScreenTutorial::Update(float deltaTime, SDL_Event e)
{
	HandleInput(e);
}

void GameScreenTutorial::HandleInput(SDL_Event e)
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

void GameScreenTutorial::HandleSelectedItem()
{
	switch (selected)
	{
	case -1:
		break;

	case 0:
		GameScreenManager::Instance()->ChangeScreen(SCREEN_MENU);
		break;
	}
}
void GameScreenTutorial::outputLine(float x, float y, string text)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < text.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

}


