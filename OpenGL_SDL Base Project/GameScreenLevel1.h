#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include <SDL.h>
#include "GameScreen.h"
#include "MeshOBJ.h"
#include "Mesh3DS.h"
#include "Wardrobe.h"
#include "GO_Table.h"
#include "GO_TV.h"
#include "GO_DodgeBall.h"
#include "GO_Dodgeball_Lives.h"
#include "Camera.h"
#include "GO_Player.h"
#include "Collisions.h"
#include <vector>

using namespace std;

class GameScreenLevel1 : GameScreen
{
//--------------------------------------------------------------------------------------------------
public:
	GameScreenLevel1();
	~GameScreenLevel1();

	bool		SetUpLevel();
	void		Render();
	void		Update(float deltaTime, SDL_Event e);
	void		SetLight();
	void		SetMaterial();
	void		outputLine(float x, float y, string text);
	void		DrawBackground();
	void		DrawFloor();
	void		Clock();

//--------------------------------------------------------------------------------------------------
private:
	
	float mCurrentTime;
	float rotation;
	Wardrobe* m_pOBJModel2;
	GO_DodgeBall* mDodgeball;
	GO_Player* mPlayer;
	GO_Dodge_Lives* mLife;
	GameObject* m_pFloor;
	Camera*		m_pCamera;
	Mesh* DodgeBall;
	Mesh* Floor;
	Mesh* Player;	
	Collision col;
	float displacement;

	vector<GO_DodgeBall *> m_DodgeBalls;
	vector<GO_Dodge_Lives *> m_Lives;

	float eyeX;
	float eyeY;
	float eyeZ;
	int hit;
	int Lives;
	int Time;
	int CurrentTime;
	int PreviousTime;
	string sTime;
	string sLives;
	bool gameOver;
	bool gameWon;
	
};


#endif //!_GAMESCREENLEVEL1_H