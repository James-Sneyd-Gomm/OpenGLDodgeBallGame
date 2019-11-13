#ifndef _GAMESCREENTUTORIAL_H
#define _GAMESCREENTUTORIAL_H

#include "GameScreen.h"
#include "GameScreenManager.h"
#include <string>
#include <vector>

using namespace std;

#define MENU_NONE -1
#define MENU_RETURN 0

class GameScreenTutorial : GameScreen
{
	//--------------------------------------------------------------------------------------------------
public:
	GameScreenTutorial();
	~GameScreenTutorial();

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


#endif //!_GAMESCREENTUTORIAL_H
