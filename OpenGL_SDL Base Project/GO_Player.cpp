#include "GO_Player.h"
#include "SoundManager.h"
#include "GameScreenManager.h"
#include <SDL.h>

using namespace std;


GO_Player::GO_Player(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad) : GameObject(startPosition, scale, rotation, mesh, rad)
{
	_vel = Vector3D();
	Lives = 3;
	dead = false;
}

GO_Player::~GO_Player()
{

}


void GO_Player::update(float deltaTime, SDL_Event e)
{
	const Uint8* currentKeyState = SDL_GetKeyboardState(NULL);

	if (GameScreenManager::Instance()->GetGameLevel() == SCREEN_LEVEL1)
	{
			if (currentKeyState[SDL_SCANCODE_W])
			{
				if (mPosition.z > -360.0f)
				{
					_vel.z += (-200.0f * deltaTime);
				}
			}

			if (currentKeyState[SDL_SCANCODE_A])
			{
				if (mPosition.x > -720.0f)
				{
					_vel.x += (-200.0f * deltaTime);
				}
			}

	
			if (currentKeyState[SDL_SCANCODE_S])
			{
				if (mPosition.z < 360.0f)
				{
					_vel.z += (200.0f * deltaTime);
				}
			}

	
			if (currentKeyState[SDL_SCANCODE_D])
			{
				if (mPosition.x < 720.0f)
				{
					_vel.x += (200.0f * deltaTime);
				}
			}
	}

	if (GameScreenManager::Instance()->GetGameLevel() == SCREEN_LEVEL2)
	{
		
		if (currentKeyState[SDL_SCANCODE_A])
		{
			if (mPosition.x > -360.0f)
			{
				_vel.x += (-200.0f * deltaTime);
			}

		}
		else if (currentKeyState[SDL_SCANCODE_D])
		{
			if (mPosition.z < 360.0f)
			{
				_vel.x += (200.0f * deltaTime);
			}

		}
	}



	mPosition += _vel;
	_vel = _vel / 2.0f;

	boundingSphere->Update(Vector3D(mPosition.x, mPosition.y + 25.0f, mPosition.z));


}

void GO_Player::LifeDown()
{
	Lives--;
	if (Lives == 0)
	{
		dead = true;
	}
}

