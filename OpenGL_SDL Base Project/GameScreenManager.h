#ifndef _GAMESCREENMANAGER_H
#define _GAMESCREENMANAGER_H

#include <SDL.h>
#include <vector>
#include "Commons.h"
#include "Constants.h"
#include <string>

using namespace std;

class GameScreen;

class GameScreenManager
{
public:
	GameScreenManager(SCREENS startScreen);
	~GameScreenManager();

	static GameScreenManager* Instance()
	{
		if (!mInstance)
		{
			mInstance = new GameScreenManager(SCREEN_MENU);
		}
		return mInstance;
	}

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS newScreen);
	int GetGameLevel() { return mCurrentLevel; }

	void SetScore(string score) { mScore = score; }
	string GetScore() { return mScore; }

private:
	GameScreen* mCurrentScreen;
	int mCurrentLevel;
	static GameScreenManager* mInstance;
	string mScore;

};


#endif //!_GAMESCREENMANAGER_H