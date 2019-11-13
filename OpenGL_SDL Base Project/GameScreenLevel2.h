#ifndef _GAMESCREENLEVEL2_H
#define _GAMESCREENLEVEL2_H

#include <SDL.h>
#include "GameScreen.h"
#include "MeshOBJ.h"
#include "Mesh3DS.h"
#include "GO_DodgeBall.h"
#include "Camera.h"
#include "GO_Player.h"
#include "Collisions.h"
#include "GO_AI.h"
#include <vector>
#include "Timer.h"
using namespace std;
class GameScreenLevel2 : GameScreen
{
public:
	GameScreenLevel2();
	~GameScreenLevel2();

	void		Update(float deltaTime, SDL_Event e);
	void		Render();
	void		SetLight();
	void		SetMaterial();
	void		outputLine(float x, float y, string text, bool b);

protected:

private:

	float mCurrentTime;
	float rotation;
	float aiSpawnDiffrence;

	GO_DodgeBall* mDodgeball;
	GO_Player* mPlayer;
	GO_AI* mAI;
	Timer* mTimer;


	vector <GO_AI*> mAIs;
	GameObject* m_pFloor;
	Camera*		m_pCamera;
	Mesh* DodgeBall;
	Mesh* Floor;
	Mesh* Player;
	Collision col;


	float eyeX;
	float eyeY;
	float eyeZ;



};

#endif //!_GAMESCREENLEVEL2_H