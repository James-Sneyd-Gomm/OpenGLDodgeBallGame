#include "MeshOBJ.h"
#include "../gl/glut.h"
#include "ObjLoader.h"
#include "Texture2d.h"
#include "TextureManager.h"


using namespace std;


MeshOBJ::MeshOBJ( string path, string modelFileName) : Mesh(path, modelFileName)
{

	strcpy(fileName, modelFileName.c_str());
	strcpy(textureName, path.c_str());
	loadModel();
	TextureName = path;

	//texture = new Texture2D();
	//texture->Load(textureName, 512, 512);
}

MeshOBJ::~MeshOBJ()
{
	delete texture;
	texture = NULL;
}

void MeshOBJ::loadModel()
{
	if (fileName[0] != '---')
		LoadOBJ(&object, fileName);
}

void MeshOBJ::loadTexture()
{
	glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texture->GetID());
	TextureManager::Instance()->BindTexture(TextureName);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

void MeshOBJ::render(Vector3D pos, Vector3D scale, float rot)
{
	

	loadTexture();
	glBegin(GL_TRIANGLES);
	for (int l_index = 0; l_index < object.polygons_qty; l_index++)
	{

		glTexCoord2f(object.mapcoord[object.indTex[l_index].a - 1].u,
			object.mapcoord[object.indTex[l_index].a - 1].v );

		glNormal3f(object.normal[object.indNorm[l_index].a - 1].x,
			object.normal[object.indNorm[l_index].a - 1].y,
			object.normal[object.indNorm[l_index].a - 1].z);

		glVertex3f(object.vertex[object.indVert[l_index].a - 1].x,
			object.vertex[object.indVert[l_index].a - 1].y,
			object.vertex[object.indVert[l_index].a - 1].z);



		glTexCoord2f(object.mapcoord[object.indTex[l_index].b - 1].u,
			object.mapcoord[object.indTex[l_index].b - 1].v );

		glNormal3f(object.normal[object.indNorm[l_index].b - 1].x,
			object.normal[object.indNorm[l_index].b - 1].y,
			object.normal[object.indNorm[l_index].b - 1].z);

		glVertex3f(object.vertex[object.indVert[l_index].b - 1].x,
			object.vertex[object.indVert[l_index].b - 1].y,
			object.vertex[object.indVert[l_index].b - 1].z);

		glTexCoord2f(object.mapcoord[object.indTex[l_index].c - 1].u,
			object.mapcoord[object.indTex[l_index].c - 1].v );

		glNormal3f(object.normal[object.indNorm[l_index].c - 1].x,
			object.normal[object.indNorm[l_index].c - 1].y,
			object.normal[object.indNorm[l_index].c - 1].z);

		glVertex3f(object.vertex[object.indVert[l_index].c - 1].x,
			object.vertex[object.indVert[l_index].c - 1].y,
			object.vertex[object.indVert[l_index].c - 1].z);



	}
	glEnd();

}