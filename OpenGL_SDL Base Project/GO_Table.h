#ifndef _GO_TABLE_H
#define _GO_TABLE_H
#include "GameObject.h"
#include "GO_TV.h"
#include <SDL.h>

class GOTable : public GameObject
{
public:
	GOTable(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad);
	~GOTable();

	void update(float deltaTime, SDL_Event e , GOTV* child);
	//void render(GOTV* child);

private:

	Vector3D tempPosChild;
};



#endif // !_GO_Table_H

