#include "GameObject.h"
#include <GL\gl.h>
#include <GL\glu.h>
#include "../gl/glut.h"

GameObject::GameObject(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad)
{
	GOmesh = mesh;
	mPosition = startPosition;
	mScale = scale;
	mRotation = rotation;
	boundingSphere = new Sphere(mPosition, rad);
}
GameObject::~GameObject()
{
	boundingSphere->Update(mPosition);
}

void GameObject::update(float deltaTime, float rotation)
{

}

void GameObject::render()
{

	glPushMatrix();
	glTranslatef(mPosition.x, mPosition.y, mPosition.z);
	glScalef(mScale.x, mScale.y, mScale.z);
	glRotatef(mRotation, 0.0f, 1.0f, 0.0f);
	GOmesh->render(mPosition,mScale,mRotation);
	glPopMatrix();
}
