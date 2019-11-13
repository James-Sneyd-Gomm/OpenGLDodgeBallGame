#ifndef GO_PLAYER_H
#define GO_PLAYER_H

#include "GameObject.h"
#include <SDL.h>


class GO_Player : public GameObject
{
public:

	GO_Player(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad);
	~GO_Player();

	void LifeDown();
	void update(float deltaTime, SDL_Event e);
	
	Vector3D GetPos() { return  mPosition; }
	bool GetDead() { return dead; }

private:
	Vector3D _vel;
	int Lives;
	bool dead;

protected:

};




#endif // !GO_PLAYER_H

