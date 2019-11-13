#ifndef _CAMERA_H
#define _CAMERA_H

#include "Commons.h"
#include <SDL.h>

class Camera
{
public:
	Camera();
	~Camera();
	static	Camera* GetInstance();
	void	Update(float deltaTime, SDL_Event e, Vector3D targetPos);
	void	Render(Vector3D targetPos);

private:
	Vector3D pos =		Vector3D(0, 0, 10);
	Vector3D fwd =		Vector3D();
	Vector3D up =		Vector3D();
	Vector3D right =	Vector3D();

	float yaw = 3.14f;
	float pitch = -0.4f;
};

#endif //_CAMERA_H
