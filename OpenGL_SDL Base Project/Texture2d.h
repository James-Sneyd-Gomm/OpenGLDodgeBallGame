#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H
#include <Windows.h>
#include <gl\GLU.h>

class Texture2D
{
private:
	GLuint _ID; // Texture ID
	int _width, _height;

public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);
	int LoadTextureTGA(const char* textureFileName);
	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }

	void BindTexture();
};
#endif