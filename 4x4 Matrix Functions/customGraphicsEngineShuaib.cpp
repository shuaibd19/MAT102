#include "olcConsoleGameEngine.h"
#include <iostream>

using namespace std;

struct mVector3
{
	float x, y, z;
};

struct triangle
{
	mVector3 v[3];
};

struct mesh
{
	vector<triangle> triangles;
};

struct mat4x4
{
	float mat[4][4] = { 0 };
};

class olcEngine3D : public olcConsoleGameEngine
{
public:
	olcEngine3D()
	{
		m_sAppName = L"3D Transformation Assessment";
	}

private:
	mesh meshCube;
	mat4x4 projectionMatrix;

	void MatrixVectorMultiplication(mVector3 &i, mVector3 &o, mat4x4 &m)
	{

		//try to implement vector and matrix multiplication using your
		//existing framework that you built
		o.x = i.x * m.mat[0][0] + i.y * m.mat[1][0] + i.z * m.mat[2][0] + m.mat[3][0];
		o.x = i.x * m.mat[0][1] + i.y * m.mat[1][1] + i.z * m.mat[2][1] + m.mat[3][1];
		o.x = i.x * m.mat[0][2] + i.y * m.mat[1][2] + i.z * m.mat[2][2] + m.mat[3][2];
		float w = o.x = i.x * m.mat[0][3] + i.y * m.mat[1][3] + i.z * m.mat[2][3] + m.mat[3][3];

		if (w != 0.0f)
		{
			o.x /= w; o.y /= w; o.z /= w;
		}
	}
public:
	bool OnUserCreate() override
	{
		meshCube.triangles = {
			//south side of cube - 2 triangles
			{0.0f, 0.0f, 0.0f,		0.0f, 1.0f, 0.0f,		1.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f,		1.0f, 1.0f, 0.0f,		1.0f, 0.0f, 0.0f},

			//east side of cube
			{1.0f, 0.0f, 0.0f,		1.0f, 1.0f, 0.0f,		1.0f, 1.0f, 1.0f},
			{1.0f, 0.0f, 0.0f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f, 1.0f},

			//north side of cube
			{1.0f, 0.0f, 1.0f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f, 1.0f},
			{1.0f, 0.0f, 1.0f,		0.0f, 1.0f, 1.0f,		0.0f, 0.0f, 1.0f},

			//west side of the cube
			{0.0f, 0.0f, 1.0f,		0.0f, 1.0f, 1.0f,		0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 1.0f,		0.0f, 1.0f, 0.0f,		0.0f, 0.0f, 0.0f},

			//top side of the cube
			{0.0f, 1.0f, 0.0f,		0.0f, 1.0f, 1.0f,		1.0f, 1.0f, 1.0f},
			{0.0f, 1.0f, 0.0f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, 0.0f},

			//bottom side of the cube
			{1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f, 0.0f},
			{1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f, 0.0f}
		};

		

		//near plane - distance from z axis
		float fNear = 0.1f;
		//far plane
		float fFar = 1000.0f;
		//field of view
		float fFov = 90.0f;
		//aspect ratio
		float fAspectRatio = (float)ScreenHeight() / (float)ScreenWidth();
		//field of view radians
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.141592653589);


		//populate projection matrix
		projectionMatrix.mat[0][0] = fAspectRatio * fFovRad;
		projectionMatrix.mat[1][1] = fFovRad;
		projectionMatrix.mat[2][2] = fFar / (fFar - fNear);
		projectionMatrix.mat[3][2] = (-fFar * fNear) / (fFar - fNear);
		projectionMatrix.mat[2][3] = 1.0f;
		projectionMatrix.mat[3][3] = 0.0f;


		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);
		//draw triangles

		for (auto tri : meshCube.triangles)
		{
			triangle triProjected;
			MatrixVectorMultiplication(tri.v[0], triProjected.v[0], projectionMatrix);
			MatrixVectorMultiplication(tri.v[1], triProjected.v[1], projectionMatrix);
			MatrixVectorMultiplication(tri.v[2], triProjected.v[2], projectionMatrix);

			//scaling the cube into view
			triProjected.v[0].x += 1.0f; 
			triProjected.v[1].x += 1.0f;
			triProjected.v[2].x += 1.0f;
			triProjected.v[0].y += 1.0f;
			triProjected.v[1].y += 1.0f;
			triProjected.v[2].y += 1.0f;

			triProjected.v[0].x *= 0.5f * (float)ScreenWidth();
			triProjected.v[1].x *= 0.5f * (float)ScreenWidth();
			triProjected.v[2].x *= 0.5f * (float)ScreenWidth();
			triProjected.v[0].y *= 0.5f * (float)ScreenHeight();
			triProjected.v[1].y *= 0.5f * (float)ScreenHeight();
			triProjected.v[2].y *= 0.5f * (float)ScreenHeight();


			DrawTriangle(triProjected.v[0].x, triProjected.v[0].y,
				triProjected.v[1].x, triProjected.v[1].y,
				triProjected.v[2].x, triProjected.v[2].y,
				PIXEL_SOLID, FG_WHITE);
		}

		return true;
	}
};

int main()
{
	olcEngine3D assessment;
	if (assessment.ConstructConsole(256, 240, 4, 4))
	{
		assessment.Start();
	}
    std::cout << "Hello World!\n"; 
}
