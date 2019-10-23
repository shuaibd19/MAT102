#pragma once
#include <math.h>
#include <iostream>
using namespace std;

#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180) 

struct MVector3
{
	float matrixForm[4] = { 1, 1, 1, 1 };
};

class CMatrix4
{
public:
	CMatrix4();
	~CMatrix4();

	void SetElement(int _iX, int _iY, float _fValue);

	float GetElement(int _iX, int _iY) const;

	static CMatrix4& Identity(CMatrix4& _rResult);

	static CMatrix4& Zero(CMatrix4& _rResult);

	static bool Equals(const CMatrix4& _rA, const CMatrix4& _rB);

	static CMatrix4& Add(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);

	static CMatrix4& Subtract(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);

	static CMatrix4& Multiply(float _fScalar, const CMatrix4& _rA, CMatrix4& _rResult);

	static CMatrix4& Multiply(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);

	static CMatrix4& Transpose(const CMatrix4& _rA, CMatrix4& _rResult);

	static MVector3& ScaleVector(float _scaleX, float _scaleY, float _scaleZ, MVector3& _vec, MVector3& _resultntV);

	static MVector3& TranslateVector(float _transX, float _transY, float _transZ, MVector3& _vec, MVector3& _resultntV);

	static MVector3& RotateZ(float _angle, MVector3& _vec, MVector3& _resultntV);

	static MVector3& RotateY(float _angle, MVector3& _vec, MVector3& _resultntV);

	static MVector3& RotateX(float _angle, MVector3& _vec, MVector3& _resultntV);

	void displayMatrix();

private:
	float m_fMatrix[4][4];

};

