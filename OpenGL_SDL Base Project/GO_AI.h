#ifndef GO_AI_H
#define GO_AI_H

#include "GameObject.h"
#include "GO_Player.h"
#include "Collisions.h"
#include "MeshOBJ.h"
#include "GO_DodgeBall.h"
#include "Timer.h"
#include <SDL.h>
#include <vector>

#define STATE_IDLE 0
#define STATE_MOVE 1
#define STATE_MOVE_RIGHT 2
#define STATE_MOVE_LEFT 3
#define STATE_ATTACK 4

using namespace std;


class GO_AI : public GameObject
{
public:

	GO_AI(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad);
	~GO_AI();

	void Update(float deltaTime, SDL_Event e, GO_Player* player);
	void UpdateBall(GO_Player* player, float deltaTime, SDL_Event e);
	void Render();
	void Move();
	void ShootBall();

	Vector3D GetPos() { return  mPosition; }

private:
	Vector3D _vel;
	Collision col;
	Mesh* DodgeBallMesh;
	GO_DodgeBall* mDodgeBallShot;
	Timer* Timer1;
	Timer* Timer2;
	Timer* TimerState;
	Vector3D weaponSpawn;
	bool timePassed;
	int RNGState;
	int RNGMove;
	int state = STATE_IDLE;
	int stateMove = STATE_MOVE_RIGHT;

	vector<GO_DodgeBall *> m_DodgeBalls;




};




#endif // !GO_AI_H
