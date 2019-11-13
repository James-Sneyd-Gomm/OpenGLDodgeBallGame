#include "GameScreenLevel1.h"
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

GameScreenLevel1::GameScreenLevel1() : GameScreen()
{
	srand(time(NULL));

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	gluPerspective(60.0f,aspect,0.1f,1000.0f);

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
	TextureManager::Instance()->LoadTexture("RubberRed.raw", 512, 512, "Rubber");

	SoundManager::Instance()->LoadSFX("Bounce.WAV", "Bounce");
	SoundManager::Instance()->LoadSFX("Scream.wav", "Scream");
	SoundManager::Instance()->LoadSFX("Victory.wav", "Win");

	glEnable(GL_TEXTURE_2D);

	DodgeBall = new MeshOBJ("Rubber", "Sphere.obj");
	Floor = new MeshOBJ("Court", "Floor.obj");
	Player = new MeshOBJ("Wood", "Player.obj");


	m_pFloor = new GameObject(Vector3D(0.0f, -5.0f, 0.0f), Vector3D(4.0f, 2.0f, 1.0f), 0.0f, Floor, 0.0f);
	mPlayer = new GO_Player(Vector3D(-700.0f, 0.0f, 0.0), Vector3D(1.0f, 1.0f, 1.0f), 0.0f, Player, 40.0f);
	m_pCamera = new Camera();

	Lives = 4;
	displacement = 0;
	Time = 0;
	CurrentTime = 0;
	PreviousTime = 0;

}

//--------------------------------------------------------------------------------------------------

GameScreenLevel1::~GameScreenLevel1()
{	
	delete m_pCamera;
	m_pCamera = NULL;
}	


void GameScreenLevel1::SetLight()
{
	lighting light = {
		{0.5f,0.5f,0.5f,1.0f},
		{0.7f,0.7f,0.7f,1.0f},
		{0.5f,0.5f,0.5f,1.0f}
	};

	// position of the light in homogeneous coordinates (x, y, z, w)
	// w should be 0 for directional light, 1 for spotlights
	float light_pos[] = { 100.0f,100.0f,1.0f,0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light.ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light.diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light.specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}

void GameScreenLevel1::SetMaterial()
{
	material material = {
		{0.80f, 0.05f, 0.05f, 1.0f},
		{0.80f, 0.05f, 0.05f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f},
		100.0f
	};

	glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
	glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);
}

//--------------------------------------------------------------------------------------------------
//void GameScreenLevel1::DrawBackground()
//{
//	/*glBindTexture(GL_TEXTURE_2D, texture->GetID());*/
//
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	glBegin(GL_QUADS);
//		glTexCoord2f(0.0f, 0.0f);
//		glVertex3f(-80.0f, -80.0f, -30.0f);
//		glTexCoord2f(1.0f, 0.0f);
//		glVertex3f(80.0f, -80.0f, -30.0f);
//		glTexCoord2f(1.0f, 1.0f);
//		glVertex3f(80.0f, 80.0f, -30.0f);
//		glTexCoord2f(0.0f, 1.0f);
//		glVertex3f(-80.0f, 80.0f, -30.0f);
//	glEnd();
//		
//}

//void GameScreenLevel1::DrawFloor()
//{
//
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0f, 0.0f);
//	glVertex3f(-720.0f, -5.0f, 360.0f);
//	glTexCoord2f(1.0f, 0.0f);
//	glVertex3f(720.0f, -5.0f, 360.0f);
//	glTexCoord2f(1.0f, 1.0f);
//	glVertex3f(720.0f, -5.0f, -360.0f);
//	glTexCoord2f(0.0f, 1.0f);
//	glVertex3f(-720.0f, -5.0f, -360.0f);
//
//	glEnd();
//
//}
	
void GameScreenLevel1::Render()
{
	//Clear the screen.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_pCamera->Render(mPlayer->GetPos());
	m_pFloor->render();
	mPlayer->render();

	for (auto mDodgeball : m_DodgeBalls)
	{
		mDodgeball->render();
	}

	if (m_Lives.size() > 0)
	{
		for (int i = 0; i < m_Lives.size() - 1; i++)
		{
			m_Lives[i]->render();
		}
	}


	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glColor3f(0.0f, 0.0f, 0.0f);
	outputLine(10, 90, "Lives:");
	outputLine(15, 90, sLives);
	outputLine(10, 85, "Time:");
	outputLine(15, 85, sTime);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();


}

//--------------------------------------------------------------------------------------------------

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	// character size 70 x 20
	mCurrentTime += deltaTime;
	rotation += 0.1;
	Clock();

	if (m_DodgeBalls.size() < 15)
	{
		mDodgeball = new GO_DodgeBall(Vector3D(1440.0f * (float)rand() / (RAND_MAX)-720.0f, 75.0f, 720.0f * (float)rand() / (RAND_MAX)-360.0f), Vector3D(1.0f, 1.0f, 1.0f), 0.0f, DodgeBall, 15.0f, Vector3D(1.0f * (float)rand() / (RAND_MAX)-0.5f, -0.5f, 1.0f * (float)rand() / (RAND_MAX)-0.5f));
		m_DodgeBalls.push_back(mDodgeball);
	}

	m_pCamera->Update(deltaTime, e, mPlayer->GetPos());
	mPlayer->update(deltaTime, e);


	if (m_Lives.size() > 0)
	{
		for (int i = 0; i < m_Lives.size() - 1; i++)
		{
			m_Lives[i]->update(deltaTime, mPlayer);
		}
	}

	if (mPlayer->GetPos().x >= 700.0f)
	{
		gameWon = true;
	}

	for (int i = 0; i < m_DodgeBalls.size() -1; i++)
	{
		int dodgeballDelete = -1;
		if (col.SphereSphereCollision(mPlayer->GetBoundingSphere(), m_DodgeBalls[i]->GetBoundingSphere()))
		{
			if (m_Lives.size() <= 3)
			{
				displacement += -30.0f;
				mLife = new GO_Dodge_Lives(mPlayer->GetPos(), Vector3D(1.0f, 1.0f, 1.0f), 0.0f, DodgeBall, 0.0f, displacement);
				m_Lives.push_back(mLife);
				Lives--;
				sLives = to_string(Lives);
			}
			else
			{
				gameOver = true;
			}
		
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

		m_DodgeBalls[i]->update(deltaTime, e);
	}


	if (gameOver == true)
	{
		SoundManager::Instance()->CallSFX("Scream");
		GameScreenManager::Instance()->ChangeScreen(SCREEN_GAMEOVER);
	}

	if (gameWon == true)
	{
		GameScreenManager::Instance()->SetScore(sTime);
		SoundManager::Instance()->CallSFX("Win");
		GameScreenManager::Instance()->ChangeScreen(SCREEN_HIGHSCORES);
	}
}

void GameScreenLevel1::outputLine(float x, float y, string text)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < text.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}

}


void GameScreenLevel1::Clock()
{
	CurrentTime = SDL_GetTicks();
	int tempTime = PreviousTime +  1000;
	if (CurrentTime > tempTime)
	{
		PreviousTime = CurrentTime;
		Time++;
		sTime = to_string(Time);
	}

}

//-------------------------------------------------------------------------------------------------