#ifndef _GO_TV_H
#define _GO_TV_H
#include "GameObject.h"
#include <SDL.h>



class GOTV : public GameObject
{
public:
	GOTV(Vector3D startPosition, Vector3D scale, float rotation, Mesh *  mesh, float rad);
	~GOTV();

	void Update(float deltaTime, SDL_Event e);
	void setPosition(Vector3D posIn);
	Vector3D getPosition();
	bool getActive();

private:
	bool active;
};




#endif // !_ACTIVE_OBJ_H
