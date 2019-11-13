#include "GO_AI.h"
#include "SoundManager.h"
#include "GameScreenManager.h"
#include "TextureManager.h"
#include <iostream>

using namespace std;

bool attack;

GO_AI::GO_AI(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad) : GameObject(startPosition, scale, rotation, mesh, rad)
{
	attack = false;
	TextureManager::Instance()->LoadTexture("RubberRed.raw", 512, 512, "Rubber");
	DodgeBallMesh = new MeshOBJ("Rubber", "Sphere.obj");
	_vel = Vector3D();
	weaponSpawn = Vector3D();
	Timer1 = new Timer();
	Timer2 = new Timer();
	TimerState = new Timer();

	timePassed = false;

}

GO_AI::~GO_AI()
{
	delete DodgeBallMesh;
	DodgeBallMesh = NULL;
	delete Timer1;
	Timer1 = NULL;
	delete Timer2;
	Timer2 = NULL;

}


void GO_AI::Render()
{
	glPushMatrix();
	glTranslatef(mPosition.x, mPosition.y, mPosition.z);
	glScalef(mScale.x, mScale.y, mScale.z);
	glRotatef(mRotation, 0.0f, 1.0f, 0.0f);
	GOmesh->render(mPosition, mScale, mRotation);
	glPopMatrix();


	if (m_DodgeBalls.size() > 0)
	{
			for (int i = 0; i < m_DodgeBalls.size(); i++)
			{
				m_DodgeBalls[i]->render();
			}
	}



}

void GO_AI::Update(float deltaTime, SDL_Event e, GO_Player* player)
{
	if (m_DodgeBalls.size() > 0)
	{
		UpdateBall(player, deltaTime, e);
	}

	//if(!attack)
	//{
	//	state = STATE_MOVE;
	//}
	//else
	//{

	//	if (TimerState->TimerCount(1))
	//	{
	//		state = STATE_ATTACK;
	//		weaponSpawn = Vector3D(mPosition.x, mPosition.y + 10.0f, mPosition.z + 1.0f);
	//		cout << mPosition.x << " " << mPosition.y << " " << mPosition.z << endl;
	//	}
	//}
	//attack = !attack;

	RNGState = 100 * (int)rand() / (RAND_MAX);

		if (RNGState < 50)
		{
			state = STATE_MOVE;

		}

		if (RNGState > 50)
		{
			state = STATE_ATTACK;
			weaponSpawn = Vector3D(mPosition.x, mPosition.y + 10.0f, mPosition.z + 1.0f);

		}



	if (state == STATE_ATTACK)
	{
		if (Timer2->TimerCount(1))
		{
			ShootBall();
		}
	}


	if (state == STATE_MOVE)
	{

		if (Timer1->TimerCount(2))
		{
			RNGMove = 100 * (int)rand() / (RAND_MAX);
		}

		if (RNGMove < 50)
		{
			stateMove = STATE_MOVE_RIGHT;

		}

		if (RNGMove > 50)
		{
			stateMove = STATE_MOVE_LEFT;
		}


		Move();
	}


}

	




void GO_AI::ShootBall()
{
	
		mDodgeBallShot = new GO_DodgeBall(weaponSpawn, Vector3D(1.0f, 1.0f, 1.0f), 0.0f, DodgeBallMesh, 15.0f, Vector3D(0.0f, 0.0f, 1.0f));
		m_DodgeBalls.push_back(mDodgeBallShot);

}


void GO_AI::UpdateBall(GO_Player* player, float deltaTime, SDL_Event e)
{
	for (int i = 0; i < m_DodgeBalls.size(); i++)
	{
		m_DodgeBalls[i]->update(deltaTime, e);

		int dodgeballDelete = -1;
		if (col.SphereSphereCollision(player->GetBoundingSphere(), m_DodgeBalls[i]->GetBoundingSphere()))
		{
			player->LifeDown();
			SoundManager::Instance()->CallSFX("Scream");
			dodgeballDelete = i;
		}

		if (m_DodgeBalls[i]->GetOutOfBounds())
		{
			dodgeballDelete = i;
		}

		if (dodgeballDelete != -1)
		{
			delete m_DodgeBalls[i];
			m_DodgeBalls[i] = nullptr;
			m_DodgeBalls.erase(m_DodgeBalls.begin() + i);
		}

	}



}

void GO_AI::Move()
{
	if (stateMove == STATE_MOVE_RIGHT)
	{
		if (mPosition.x < 350.0f)
		{
			mPosition.x += 0.5;
		}
		else if (mPosition.x >= 350.0f)
		{
			stateMove = STATE_MOVE_LEFT;
		}
	}

	if (stateMove == STATE_MOVE_LEFT)
	{
		if (mPosition.x > -350.0f)
		{
			mPosition.x -= 0.5;
		}
		else if (mPosition.x <= -350.0f)
		{
			stateMove = STATE_MOVE_RIGHT;
		}
	}

}
