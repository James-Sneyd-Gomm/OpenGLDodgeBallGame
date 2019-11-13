#include "GO_DodgeBall.h"
#include "SoundManager.h"
#include <iostream>





GO_DodgeBall::GO_DodgeBall(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad, Vector3D vel) : GameObject(startPosition, scale, rotation, mesh, rad)
{
	velocity = vel;
	outOfBounds = false;
	cout << mPosition.x << " " << mPosition.y << " " << mPosition.z << endl;
}

GO_DodgeBall::~GO_DodgeBall()
{

}


void GO_DodgeBall::update(float deltaTime, SDL_Event e)
{
	mPosition += velocity;
	boundingSphere->Update(mPosition);

	if (mPosition.y < -5.0f)
	{
		velocity.y = velocity.y * -1;
		SoundManager::Instance()->CallSFX("Bounce");
	}

	if (mPosition.x <= -720.f || mPosition.x >= 720.f)
	{
		outOfBounds = true;
	}

	if (mPosition.z <= -360.f || mPosition.z >= 360.f)
	{
		outOfBounds = true;
	}

	if (mPosition.y >= 250.0f)
	{
		outOfBounds = true;
	}


}