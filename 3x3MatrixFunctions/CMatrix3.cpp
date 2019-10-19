#include "CMatrix3.h"

/*Author: Ahmad Shuaib Dorani
Student ID: 00290332T
Date: 25/09/2019
******************************/


/***********************
* Name of the Function: CMatrix3 - Constructor
* @parameter:
* @return:
********************/

CMatrix3::CMatrix3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_fMatrix[i][j] = 0;
		}
	}
}

CMatrix3::~CMatrix3()
{
}

/***********************
* Name of the Function: SetElement - Sets an element of matrix
* @parameter: int _iX and _iY as the indexes of the element and float _fValue as the value to be set
* @return: nothing
********************/
void CMatrix3::SetElement(int _iX, int _iY, float _fValue)
{
	m_fMatrix[_iX][_iY] = _fValue;
}

/***********************
* Name of the Function: GetElement - Gets an element of matrix
* @parameter: int _iX and _iY as the indexes of the element
* @return: float value of element at index
********************/
float CMatrix3::GetElement(int _iX, int _iY) const
{
	return m_fMatrix[_iX][_iY];
}

/***********************
* Name of the Function: Idetity - Create an identity matrix
* @parameter: CMatrix3 _rResult as the matrix to be used as identity
* @return: _rResult
********************/
CMatrix3 & CMatrix3::Identity(CMatrix3 & _rResult)
{
	//1st row
	_rResult.SetElement(0, 0, 1);
	_rResult.SetElement(0, 1, 0);
	_rResult.SetElement(0, 2, 0);

	//2nd row
	_rResult.SetElement(1, 0, 0);
	_rResult.SetElement(1, 1, 1);
	_rResult.SetElement(1, 2, 0);

	//3rd row
	_rResult.SetElement(2, 0, 0);
	_rResult.SetElement(2, 1, 0);
	_rResult.SetElement(2, 2, 1);
	return _rResult;
}

CMatrix3 & CMatrix3::Zero(CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_rResult.SetElement(i, j, 0);
		}
	}

	return _rResult;
}

bool CMatrix3::Equals(const CMatrix3 & _rA, const CMatrix3 & _rB)
{
	bool result = true;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (_rA.GetElement(i, j) != _rB.GetElement(i, j))
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

CMatrix3 & CMatrix3::Add(const CMatrix3 & _rA, const CMatrix3 & _rB, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] + _rB.m_fMatrix[i][j];
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Subtract(const CMatrix3 & _rA, const CMatrix3 & _rB, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] - _rB.m_fMatrix[i][j];
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Multiply(float _fScalar, const CMatrix3 & _rA, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] * _fScalar;
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Multiply(const CMatrix3 & _rA, const CMatrix3 & _rB, CMatrix3 & _rResult)
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				_rResult.m_fMatrix[i][j] += _rA.m_fMatrix[i][k] * _rB.m_fMatrix[k][j];
			}
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Transpose(const CMatrix3 & _rA, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[j][i];
		}
	}
	return _rResult;
}

MVector2 & CMatrix3::ScaleVector(float _scaleX, float _scaleY, MVector2 & _vec, MVector2 & _resultntV)
{
	CMatrix3 scaleMatrix;
	scaleMatrix.Identity(scaleMatrix);
	scaleMatrix.SetElement(0, 0, _scaleX);
	scaleMatrix.SetElement(1, 1, _scaleY);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_resultntV.matrixForm[i] += (scaleMatrix.m_fMatrix[i][j] * _vec.matrixForm[i]);
		}
	}

	return _resultntV;
}


MVector2 & CMatrix3::TranslateVector(float _transX, float _transY, MVector2 & _vec, MVector2 & _resultntV)
{
	CMatrix3 transMatrix;
	transMatrix.Identity(transMatrix);
	transMatrix.SetElement(0, 2, _transX);
	transMatrix.SetElement(1, 2, _transY);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_resultntV.matrixForm[i] += (transMatrix.m_fMatrix[i][j] * _vec.matrixForm[i]);
		}
	}

	return _resultntV;
}

MVector2 & CMatrix3::RotateVector(float _angle, MVector2 & _vec, MVector2 & _resultntV)
{
	CMatrix3 rotateMatrix;
	rotateMatrix.Identity(rotateMatrix);
	rotateMatrix.SetElement(0, 0, cos(toRadians(_angle)));
	rotateMatrix.SetElement(0, 1, -1*(sin(toRadians(_angle))));
	rotateMatrix.SetElement(1, 0, sin(toRadians(_angle)));
	rotateMatrix.SetElement(0, 1, -1 * (cos(toRadians(_angle))));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_resultntV.matrixForm[i] += (rotateMatrix.m_fMatrix[i][j] * _vec.matrixForm[i]);
		}
	}
	
	return _resultntV;
}

float CMatrix3::toRadians(float angleD)
{
	float x = angleD * 3.14159 / 180;
	return x;
}

void CMatrix3::displayMatrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << m_fMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}
