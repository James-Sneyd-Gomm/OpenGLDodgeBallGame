#ifndef GO_DODGE_BALL_H
#define GO_DODGE_BALL_H

#include "GameObject.h"
#include <SDL.h>



class GO_DodgeBall : public GameObject
{
public:
	GO_DodgeBall(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad, Vector3D Vel);
	~GO_DodgeBall();
	void update(float deltaTime, SDL_Event e);

	bool GetOutOfBounds() { return outOfBounds; };

private:
	Vector3D velocity;
	bool outOfBounds;

};


#endif // !GO_DODGE_BALL_H
