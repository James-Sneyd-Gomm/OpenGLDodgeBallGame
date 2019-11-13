#ifndef _PYRAMID_H
#define _PYRAMID_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Commons.h"

class Pyramid
{
private:
	Vertex3D * indexedVertices;
	short * indices;
	int numVertices;
	int indexCount;

	bool Load(char* path);
	void DrawTriangle(short a, short b, short c);

public:
	Pyramid();
	~Pyramid();

	void Draw();
	void Update();
};

#endif
