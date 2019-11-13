#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H
#include <map>
#include <string>
#include <SDL_mixer.h>
#include <SDL.h>

using namespace std;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	static SoundManager* Instance()
	{
		if (!mInstance)
		{
			mInstance = new SoundManager();
		}
		return mInstance;
	}

	void LoadSFX(char* soundPath, string SFXName);
	void CallSFX(string name);


private:
	static SoundManager* mInstance;
	map<string, Mix_Chunk*> mSFXs;
};


#endif // !SOUND_MANAGER_H




