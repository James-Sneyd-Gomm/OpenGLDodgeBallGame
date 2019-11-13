#ifndef MESH_H
#define MESH_H
#include "Commons.h"
#include <string>
#include "Texture2d.h"
using std::string;


class Mesh
{
public:
	Mesh(string Texturepath, string modelFileName);
	Mesh();
	~Mesh();

	virtual void render(Vector3D pos, Vector3D scale, float rot);
	virtual void loadModel();
	virtual void loadTexture();


protected:

	char fileName[20];
	char textureName[20];
	Texture2D* texture;





};






#endif // !MESH_H

