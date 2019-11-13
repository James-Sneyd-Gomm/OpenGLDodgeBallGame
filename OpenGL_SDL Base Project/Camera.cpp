#include "Camera.h"
#include "Constants.h"
#include <math.h>
#include "../gl/glut.h"


static Camera* instance = 0;
static float moveSpeed = 50.0f;
static float lookSpeed = 0.1f;

Camera::Camera()
{

}

Camera::~Camera()
{

}

Camera* Camera::GetInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}

	return instance;
}

void Camera::Update(float deltaTime, SDL_Event e, Vector3D targetPos)
{
	fwd = Vector3D(cos(pitch) * sin(yaw), sin(pitch), cos(pitch) * cos(yaw));
	pos = Vector3D(targetPos.x, targetPos.y + 150 , targetPos.z + 300);
	//fwd = Vector3D(targetPos.x, targetPos.y, targetPos.z);
	right = Vector3D(sin(yaw - 3.14 / 20.f), 0, cos(yaw - 3.14 / 2.0f));
	//up = Vector3D(0.0f, 1.0f, 0.0f);
	up = Vector3D((right.y * fwd.z) - (right.z * fwd.y), (right.z * fwd.x) - (right.x * fwd.z), (right.x * fwd.y) - (right.y * fwd.x));


	/*if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			pos += fwd * moveSpeed;
			break;
		case SDLK_s:
			pos -= fwd * moveSpeed;
			break;
		case SDLK_d:
			pos += right * moveSpeed;
			break;
		case SDLK_a:
			pos -= right * moveSpeed;
			break;
		case SDLK_UP:
			pitch += lookSpeed;
			break;
		case SDLK_DOWN:
			pitch -= lookSpeed;
			break;
		case SDLK_LEFT:
			yaw += lookSpeed;
			break;
		case SDLK_RIGHT:
			yaw -= lookSpeed;
			break;
		}
	}*/
}

void Camera::Render(Vector3D targetPos)
{
	Vector3D lookatPos = pos + fwd;
	//pos = Vector3D(targetPos.x, targetPos.y , targetPos.z );
	//Vector3D lookatPos = pos + targetPos;

	glLoadIdentity();
	gluLookAt(pos.x, pos.y, pos.z, lookatPos.x, lookatPos.y, lookatPos.z, up.x, up.y, up.z);
}



