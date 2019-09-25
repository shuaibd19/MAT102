#pragma once
#include <iostream>
using namespace std;

class CMatrix3
{
public:
	CMatrix3();
	~CMatrix3();

	void SetElement(int _iX, int _iY, float _fValue);

	float GetElement(int _iX, int _iY) const;

	static CMatrix3& Identity(CMatrix3& _rResult);

	static CMatrix3& Zero(CMatrix3& _rResult);

	static bool Equals(const CMatrix3& _rA, const CMatrix3& _rB);

	static CMatrix3& Add(const CMatrix3& _rA, const CMatrix3& _rB, CMatrix3& _rResult);

	static CMatrix3& Subtract(const CMatrix3& _rA, const CMatrix3& _rB, CMatrix3& _rResult);

	static CMatrix3& Multiply(float _fScalar, const CMatrix3& _rA, CMatrix3& _rResult);

	static CMatrix3& Multiply(const CMatrix3& _rA, const CMatrix3& _rB, CMatrix3& _rResult);

	static CMatrix3& Transpose(const CMatrix3& _rA, CMatrix3& _rResult);

	void displayMatrix();

private: 
	float m_fMatrix[3][3];
};