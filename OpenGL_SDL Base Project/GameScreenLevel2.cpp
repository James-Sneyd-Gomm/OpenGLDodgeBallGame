#include "GameScreenLevel2.h"
#include "GameScreenManager.h"
#include <time.h>
#include <windows.h>
#include <string>
#include "../gl/glut.h"
#include "Constants.h"
#include "Commons.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include <iostream>

using namespace::std;

//--------------------------------------------------------------------------------------------------

GameScreenLevel2::GameScreenLevel2() : GameScreen()
{
	srand(time(NULL));

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	gluPerspective(60.0f, aspect, 0.1f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_CULL_FACE);								//Stop calculation of inside faces
	glEnable(GL_DEPTH_TEST);							//Hidden surface removal

														//clear background colour.
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	rotation = 30.0f;

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	TextureManager::Instance()->LoadTexture("Spacedust.raw", 1920, 1536, "stars");
	TextureManager::Instance()->LoadTexture("Wood.raw", 512, 512, "Wood");
	TextureManager::Instance()->LoadTexture("Court.raw", 1024, 512, "Court");
	
	SoundManager::Instance()->LoadSFX("Scream.wav", "Scream");
	SoundManager::Instance()->LoadSFX("Power Up!.wav", "Power");
	SoundManager::Instance()->LoadSFX("Welcome To Your Doom!.wav", "Doom");


	glEnable(GL_TEXTURE_2D);


	Floor = new MeshOBJ("Court", "Floor.obj");
	Player = new MeshOBJ("Wood", "Player.obj");

	aiSpawnDiffrence = 100.0f;
	m_pFloor = new GameObject(Vector3D(0.0f, -5.0f, 0.0f), Vector3D(1.0f, 1.0f, 2.0f), 90.0f, Floor, 0.0f);
	mPlayer = new GO_Player(Vector3D(0.0f, 0.0f, 200.0), Vector3D(1.0f, 1.0f, 1.0f), 0.0f, Player, 40.0f);
	mAI = new GO_AI(Vector3D(0.0f, 0.0f, -50.0), Vector3D(1.0f, 1.0f, 1.0f), 0.0f, Player, 0.0f);
	mAIs.push_back(mAI);
	m_pCamera = new Camera();
	mTimer = new Timer();


	SoundManager::Instance()->CallSFX("Doom");

}

//--------------------------------------------------------------------------------------------------

GameScreenLevel2::~GameScreenLevel2()
{
	delete m_pCamera;
	m_pCamera = NULL;
}


void GameScreenLevel2::SetLight()
{
	lighting light = {
		{ 0.5f,0.5f,0.5f,1.0f },
	{ 0.7f,0.7f,0.7f,1.0f },
	{ 0.5f,0.5f,0.5f,1.0f }
	};

	// position of the light in homogeneous coordinates (x, y, z, w)
	// w should be 0 for directional light, 1 for spotlights
	float light_pos[] = { 100.0f,100.0f,1.0f,0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light.ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light.diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light.specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}

void GameScreenLevel2::SetMaterial()
{
	material material = {
		{ 0.80f, 0.05f, 0.05f, 1.0f },
	{ 0.80f, 0.05f, 0.05f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	100.0f
	};

	glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
	glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
}



void GameScreenLevel2::Render()
{
	//Clear the screen.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_pCamera->Render(mPlayer->GetPos());
	m_pFloor->render();
	mPlayer->render();


	for (int i = 0; i < mAIs.size(); i++)
	{
		mAIs[i]->Render();
	}


	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();


}

//--------------------------------------------------------------------------------------------------

void GameScreenLevel2::Update(float deltaTime, SDL_Event e)
{
	// character size 70 x 20
	mCurrentTime += deltaTime;
	rotation += 0.1;


	m_pCamera->Update(deltaTime, e, mPlayer->GetPos());
	mPlayer->update(deltaTime, e);


	for (int i = 0; i < mAIs.size(); i++)
	{
		mAIs[i]->Update(deltaTime, e, mPlayer);
	}



	if (mTimer->TimerCount(30))
	{
		if (mAIs.size() < 3)
		{
			mAI = new GO_AI(Vector3D(0.0f, 0.0f, -50.0 - (aiSpawnDiffrence * mAIs.size())), Vector3D(1.0f, 1.0f, 1.0f), 0.0f, Player, 0.0f);
			mAIs.push_back(mAI);
			SoundManager::Instance()->CallSFX("Power");
		}
	}

	if (mPlayer->GetDead() == true)
	{
		GameScreenManager::Instance()->ChangeScreen(SCREEN_GAMEOVER);
		
	}

}

void GameScreenLevel2::outputLine(float x, float y, string text, bool b)
{

	glRasterPos2f(x, y);
	for (int i = 0; i < text.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}

}

//-------------------------------------------------------------------------------------------------
