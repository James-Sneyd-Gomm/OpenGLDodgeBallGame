#include "TextureManager.h"
#include <iostream>

TextureManager* TextureManager::mInstance;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{

}

void TextureManager::LoadTexture(char* texturePath, int width, int height, string textureName)
{
	string name = textureName;
	Texture2D* texture;

	map<std::string, Texture2D*>::iterator it = Textures.find(name);
	if (it != Textures.end())
	{
		return;
	}
	else
	{
		texture = new Texture2D();
		texture->Load(texturePath, width, height);
		Textures.insert(pair<string, Texture2D*>(name, texture));
	}
}

void TextureManager::BindTexture(string name)
{
	Texture2D* texture = Textures.find(name)->second;
	if (!texture)
	{
		cout << "Texture" << name << "not found" << endl;
	}
	else
	{
		texture->BindTexture();
	}
}

