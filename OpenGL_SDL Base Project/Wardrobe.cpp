#include "Wardrobe.h"


Wardrobe::Wardrobe(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad) : GameObject (startPosition, scale, rotation, mesh, rad)
{
	rev = false;
	count = 0;

}

Wardrobe::~Wardrobe()
{

}

bool Wardrobe::getRev()
{
	return rev;
}

void Wardrobe::update(float deltaTime, float rotation, SDL_Event e)
{
	boundingSphere->Update(mPosition);

	switch (e.key.keysym.sym)
	{
	case SDLK_1:
		if (rev == true)
		{
			rev = false;
			
		}
		break;
	case SDLK_2:
		if (rev == false)
		{
			rev = true;
		}
		break;
	}

	if (rev == true)
	{
		mRotation -= 0.1f;
	}
	else if (rev == false)
	{
		mRotation += 0.1f;
	}

	bob();

}

void Wardrobe::bob()
{
	if (up == false)
	{
		mPosition.y -= 0.001f;
		count++;
		if (count == 600)
		{
			up = true;
			count = 0;
		}
	}

	if (up == true)
	{
		mPosition.y += 0.001f;
		count++;
		if (count == 600)
		{
			up = false;
			count = 0;
		}
	}
}
