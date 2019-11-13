
#pragma once
#define MAX_VERTICES 100000
#define MAX_POLYGONS 100000
enum SCREENS
{
	SCREEN_INTRO = 0,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_TUTORIAL,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES
};

struct Rect2D
{
	float x;
	float y;
	float width;
	float height;

	Rect2D(float initialX, float initialY, float initialWidth, float initialHeight)
	{
		x = initialX;
		y = initialY;
		width  = initialWidth;
		height = initialHeight;
	}
};

struct Vector2D
{
	float x;
	float y;

	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float initialX, float initialY)
	{
		x = initialX;
		y = initialY;
	}
};

struct Vertex3D
{
	float x;
	float y;
	float z;

	Vertex3D()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vertex3D(float initX, float initY, float initZ)
	{
		x = initX;
		y = initY;
		z = initZ;
	}
};

struct Vector3D
{
	float x;
	float y;
	float z;

	Vector3D()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3D(float initX, float initY, float initZ)
	{
		x = initX;
		y = initY;
		z = initZ;
	}

	Vector3D operator* (float scaler)
	{
		return Vector3D(x * scaler, y * scaler, z * scaler);
	}

	Vector3D operator/ (float scalar)
	{
		return Vector3D(x / scalar, y / scalar, z / scalar);
	}

	Vector3D operator+ (const Vector3D& other)
	{
		return Vector3D(x + other.x, y + other.y, z + other.z);
	}

	Vector3D operator+= (const Vector3D& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3D operator-= (const Vector3D& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3D Invert()
	{
		x = x * -1;
		y = y * -1;
		z = z * -1;
		return *this;
	}
};


struct lighting
{
	float ambient[4];
	float diffuse[4];
	float specular[4];
};

struct material
{
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float shininess;
};

struct Triangle
{
	int a;
	int b;
	int c;
};

struct TexCoord
{
	float u;
	float v;
};


typedef struct
{
	char name[20];
	int vertices_qty;
	int polygons_qty;
	Vertex3D vertex[MAX_VERTICES];
	Triangle polygon[MAX_POLYGONS];
	TexCoord mapcoord[MAX_VERTICES];
	int id_texture;
} obj_type, *obj_type_ptr;

typedef struct
{
	char name[20];
	int vertices_qty;
	int polygons_qty;
	Vertex3D vertex[MAX_VERTICES];
	Vector3D normal[MAX_VERTICES];
	Triangle indVert[MAX_POLYGONS];
	Triangle indTex[MAX_POLYGONS];
	Triangle indNorm[MAX_POLYGONS];
	TexCoord mapcoord[MAX_VERTICES];
	int id_texture;
} obj_typeObj, *obj_type_ptrObj;



