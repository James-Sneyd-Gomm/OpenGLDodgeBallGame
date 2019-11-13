#ifndef _MESH_OBJ_H_
#define _MESH_OBJ_H_

#include "Commons.h"
#include <string>;
#include "Texture2d.h"
#include "Mesh.h"
using std::string;

class MeshOBJ : public Mesh
{
public:
	MeshOBJ(string Texturepath, string modelFileName);
	~MeshOBJ();


	void render(Vector3D pos, Vector3D scale, float rot);
	void loadModel();
	void loadTexture();

protected:

	obj_typeObj object;
	string TextureName;
};
#endif // !_MESH_OBJ_H_
