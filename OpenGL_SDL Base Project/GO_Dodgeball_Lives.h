#ifndef GO_DODGEBALL_LIVES_H
#define GO_DODGEBALL_LIVES_H
#include "GameObject.h"
#include "GO_Player.h"

class GO_Dodge_Lives : public GameObject
{
public:
	GO_Dodge_Lives(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad , float displacement);
	~GO_Dodge_Lives();

	void update(float deltaTime, GO_Player* player);

private:

	float _displacement;
};




#endif // !GO_DODGEBALL_LIVES_H

