#include "Mesh3DS.h"
#include "../gl/glut.h"
#include "3dsLoader.h"

using namespace std;


Mesh3DS::Mesh3DS(string texturePath, string modelFileName) : Mesh (texturePath, modelFileName)
{
	strcpy(fileName, modelFileName.c_str());
	loadModel();
}

Mesh3DS::~Mesh3DS()
{

}

void Mesh3DS::loadModel()
{
	if (fileName[0] != '---')
		Load3DS(&object, fileName);
}

void Mesh3DS::loadTexture()
{

}


void Mesh3DS::render(Vector3D pos, Vector3D scale, float rot)
{

	glBegin(GL_TRIANGLES);
	for (int l_index = 0; l_index < object.polygons_qty; l_index++)
	{
		glNormal3f(object.vertex[object.polygon[l_index].a].x,
			object.vertex[object.polygon[l_index].a].y,
			object.vertex[object.polygon[l_index].a].z);

		glVertex3f(object.vertex[object.polygon[l_index].a].x,
				object.vertex[object.polygon[l_index].a].y,
				object.vertex[object.polygon[l_index].a].z);


		glNormal3f(object.vertex[object.polygon[l_index].b].x,
			object.vertex[object.polygon[l_index].b].y,
			object.vertex[object.polygon[l_index].b].z);


		glVertex3f(object.vertex[object.polygon[l_index].b].x,
			object.vertex[object.polygon[l_index].b].y,
			object.vertex[object.polygon[l_index].b].z);

		glNormal3f(object.vertex[object.polygon[l_index].c].x,
			object.vertex[object.polygon[l_index].c].y,
			object.vertex[object.polygon[l_index].c].z);

		glVertex3f(object.vertex[object.polygon[l_index].c].x,
			object.vertex[object.polygon[l_index].c].y,
			object.vertex[object.polygon[l_index].c].z);

	}
	glEnd();
}
