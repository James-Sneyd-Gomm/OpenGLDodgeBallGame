#include "Pyramid.h"
#include <fstream>
#include <iostream>
using namespace std;


Pyramid::Pyramid()
{
	Load("Pyramid.txt");
}

Pyramid::~Pyramid()
{
	delete indexedVertices;
	delete indices;
}

bool Pyramid::Load(char* path)
{
	ifstream inFile;
	inFile.open(path);

	if (!inFile.good())
	{
		cerr << "Can't open model file" << path << endl;
		return false;
	}

	inFile >> numVertices;

	if (numVertices > 0)
	{
		indexedVertices = new Vertex3D[numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			inFile >> indexedVertices[i].x;
			inFile >> indexedVertices[i].y;
			inFile >> indexedVertices[i].z;
		}
	}

	int numTriangles;
	inFile >> numTriangles;
	indexCount = numTriangles * 3;

	if (indexCount > 0)
	{
		indices = new short[indexCount];
		for (int i = 0; i < indexCount; i++)
		{
			inFile >> indices[i];
		}
		inFile.close();
		return true;
	}
}

void Pyramid::Draw()
{
	for (int i = 0; i < indexCount; i += 3)
	{
		DrawTriangle(indices[i], indices[i + 1], indices[i + 2]);
	}
}

void Pyramid::DrawTriangle(short a, short b, short c)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(indexedVertices[a].x, indexedVertices[a].y, indexedVertices[a].z);
	glVertex3f(indexedVertices[b].x, indexedVertices[b].y, indexedVertices[b].z);
	glVertex3f(indexedVertices[c].x, indexedVertices[c].y, indexedVertices[c].z);
	glEnd();
}