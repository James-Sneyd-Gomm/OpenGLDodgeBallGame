#include "GO_Table.h"



GOTable::GOTable(Vector3D startPosition, Vector3D scale, float rotation, Mesh* mesh, float rad) :GameObject(startPosition, scale, rotation, mesh, rad)
{
}


GOTable::~GOTable()
{

}




void GOTable::update(float deltaTime, SDL_Event e, GOTV* child)
{
	tempPosChild = child->getPosition();

	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_z:
			mPosition.x -= 0.1f;
			tempPosChild.x -= 0.1f;
			child->setPosition(tempPosChild);
			break;
		case SDLK_x:
			mPosition.x += 0.1f;
			tempPosChild.x += 0.1f;
			child->setPosition(tempPosChild);
			break;
		case SDLK_c:
			mPosition.z += 0.1f;
			tempPosChild.z += 0.1f;
			child->setPosition(tempPosChild);
			break;
		case SDLK_v:
			mPosition.z -= 0.1f;
			tempPosChild.z -= 0.1f;
			child->setPosition(tempPosChild);
			break;
		}

	}
}