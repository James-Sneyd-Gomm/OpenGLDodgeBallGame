#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Commons.h"
#include "Collisions.h"
#include "Mesh.h"

class GameObject 
{
public:
	GameObject(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad);
	~GameObject();

	virtual void update(float deltaTime, float rotation);
	virtual void render();

	Sphere* GetBoundingSphere() { return boundingSphere; }




protected:
	Vector3D mPosition;
	Vector3D mScale;
	float mRotation;
	Mesh * GOmesh;
	Sphere* boundingSphere;
	bool test;
};
#endif // !GAME_OBJECT_H

