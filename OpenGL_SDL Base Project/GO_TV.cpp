#include "GO_TV.h"



GOTV::GOTV(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad) : GameObject (startPosition, scale, rotation, mesh, rad)
{
	active = false;

}

GOTV::~GOTV()
{

}

bool GOTV::getActive()
{
	return active;
}

void GOTV::setPosition(Vector3D posIn)
{
	mPosition.x = posIn.x;
	mPosition.y = posIn.y;
	mPosition.z = posIn.z;
}

Vector3D GOTV::getPosition()
{
	return mPosition;
}

void GOTV::Update(float deltaTime, SDL_Event e)
{
	boundingSphere->Update(mPosition);
	switch (e.key.keysym.sym)
	{
	case SDLK_3:
		if (active == true)
		{
			active = false;
			mPosition.y -= 1.5f;

		}
		break;
	case SDLK_4:
		if (active == false)
		{
			active = true;
			mPosition.y += 1.5f;
		}
		break;
	}

	if (active == true)
	{
		mRotation += 0.1f;
	}
	if (active == false)
	{
		mRotation = 0.0f;
	}
}