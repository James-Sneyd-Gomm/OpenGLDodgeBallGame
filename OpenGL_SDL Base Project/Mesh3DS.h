#ifndef _MESH3DS_H_
#define _MESH3DS_H_

#include "Commons.h"
#include "Mesh.h"
#include <string>;
using std::string;

class Mesh3DS : public Mesh
{
public:
	Mesh3DS(string texturePath, string modelFileName);
	~Mesh3DS();


	void render(Vector3D pos, Vector3D scale, float rot);
	void loadModel();
	void loadTexture();

protected:

	obj_type object;
};
#endif // !_MESH3DS_H_
