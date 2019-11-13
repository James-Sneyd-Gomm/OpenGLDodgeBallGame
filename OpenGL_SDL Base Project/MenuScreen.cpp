#include "MenuScreen.h"
#include "../gl/glut.h"



MenuScreen::MenuScreen() : GameScreen()
{
	glDisable(GL_LIGHTING);
	mInteractiveText.push_back("Level 1");
	mInteractiveText.push_back("Level 2");
	mInteractiveText.push_back("Tutorial");
	mInteractiveText.push_back("Exit");

	if (mInteractiveText.size() != 0)
	{
		selected = MENU_LEVEL1;
	}
	mStaticText.push_back("Welcome to DodgeBall!");
	mStaticText.push_back("Use the arrow keys to choose an option.");
	mStaticText.push_back("Hit Enter to choose your option.");

}


MenuScreen::~MenuScreen()
{
}

void MenuScreen::Render()
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

void MenuScreen::Update(float deltaTime, SDL_Event e)
{
	HandleInput(e);
}

void MenuScreen::HandleInput(SDL_Event e)
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


void MenuScreen::HandleSelectedItem()
{
	switch (selected)
	{
	case -1:
		break;

	case 0:
		GameScreenManager::Instance()->ChangeScreen(SCREEN_LEVEL1);
		break;

	case 1:
		GameScreenManager::Instance()->ChangeScreen(SCREEN_LEVEL2);
		break;

	case 2:
		GameScreenManager::Instance()->ChangeScreen(SCREEN_TUTORIAL);
		break;

	case 3:
		SDL_Event quit;
		quit.type = SDL_QUIT;
		SDL_PushEvent(&quit);
		break;


	}
}


void MenuScreen::outputLine(float x, float y, string text)
{

	glRasterPos2f(x, y);
	for (int i = 0; i < text.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

}