#include "GO_Dodgeball_Lives.h" 


GO_Dodge_Lives::GO_Dodge_Lives(Vector3D startPosition, Vector3D scale, float rotation, Mesh * mesh, float rad, float displacement) : GameObject(startPosition, scale, rotation, mesh, rad)
{
	_displacement = displacement;
}

GO_Dodge_Lives::~GO_Dodge_Lives()
{
}

void GO_Dodge_Lives::update(float deltaTime, GO_Player* player)
{
	mPosition.x = (player->GetPos().x + _displacement);
	mPosition.y = (player->GetPos().y + 30.0f);
	mPosition.z = player->GetPos().z;
}