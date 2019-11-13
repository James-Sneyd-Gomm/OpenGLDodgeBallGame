#ifndef _GAMESCREENVICTORY_H
#define _GAMESCREENVICTORY_H

#include "GameScreen.h"
#include "GameScreenManager.h"
#include <string>
#include <vector>

using namespace std;

#define MENU_NONE -1
#define MENU_RETURN 0
#define MENU_EXIT 1

class GameScreenVictory : GameScreen
{
	//--------------------------------------------------------------------------------------------------
public:
	GameScreenVictory();
	~GameScreenVictory();

	void Render();
	void Update(float deltaTime, SDL_Event e);
	void outputLine(float x, float y, string text);

protected:
	void HandleInput(SDL_Event e);
	vector <string> mStaticText;
	vector <string> mInteractiveText;
	string mScore;

private:
	int selected = MENU_NONE;
	void HandleSelectedItem();

};


#endif //!_GAMESCREENVICTORY_H
