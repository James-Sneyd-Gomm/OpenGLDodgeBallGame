#ifndef _TEXTURE_MANAGER_H
#define _TEXTURE_MANAGER_H
#include <map>
#include <string>
#include "Texture2d.h"

using namespace std;


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static TextureManager* Instance()
	{
		if (!mInstance)
		{
			mInstance = new TextureManager();
		}
		return mInstance;
	}
	void LoadTexture(char* texturePath, int width, int height, string textureName);	
	void BindTexture(string name);
		
private:


	static TextureManager* mInstance;
	map<string, Texture2D*> Textures;
	
};


#endif // !_TEXTURE_MANAGER_H

