#include "SoundManager.h"
#include <iostream>

SoundManager* SoundManager::mInstance;

SoundManager::SoundManager()
{
	//	Initialise the Mixer.
		if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0)
		{
			cout << "Mixer could not initialise. Error: " << Mix_GetError();
		}
}


SoundManager::~SoundManager()
{
}


void SoundManager::LoadSFX(char* SFXPath, string SFXName)
{
	string name = SFXName;
	Mix_Chunk* SFX;

	map<std::string, Mix_Chunk*>::iterator it = mSFXs.find(name);
	if (it != mSFXs.end())
	{
		return;
	}
	else
	{
		SFX = Mix_LoadWAV(SFXPath);
		mSFXs.insert(pair<string, Mix_Chunk*>(name, SFX));
	}
}

void SoundManager::CallSFX(string name)
{
	Mix_Chunk* SFX = mSFXs.find(name)->second;
	if (!SFX)
	{
		cout << "SFX" << name << "not found" << endl;
	}
	else
	{
		Mix_PlayChannel(-1, SFX, 0);
	}


}
