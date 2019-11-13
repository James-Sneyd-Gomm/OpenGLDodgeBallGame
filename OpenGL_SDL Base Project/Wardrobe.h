#ifndef  _WARDROBE_H
#define _WARDROBE_H
#include "GameObject.h"
#include <SDL.h>

class Wardrobe : public GameObject
{
public:
	Wardrobe(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad);
	~Wardrobe();
	void update(float deltaTime, float rotation, SDL_Event e);
	void bob();
	bool getRev();

private:
	float rotC;
	int count;
	bool rev = false;
	bool up = false;
};





#endif // ! _WARDROBE_H

