#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include "GameScreen.h"
#include "GameScreenManager.h"
#include <string>
#include <vector>

using namespace std;

#define MENU_NONE -1
#define MENU_LEVEL1 0
#define MENU_LEVEL2 1
#define MENU_TUTORIAL 2
#define MENU_EXIT 3

class MenuScreen : GameScreen
{
public:
	MenuScreen();
	~MenuScreen();

	void Render();
	void Update(float deltaTime, SDL_Event e);
	void outputLine(float x, float y, string text);

protected:
	void HandleInput(SDL_Event e);
	vector <string> mStaticText;
	vector <string> mInteractiveText;

private:
	int selected = MENU_NONE;
	void HandleSelectedItem();
};


#endif // !MENU_SCREEN_H


