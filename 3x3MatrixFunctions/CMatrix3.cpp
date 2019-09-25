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
	bool result = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (_rA.GetElement(i,j) == _rB.GetElement(i,j))
			{
				result = true;
			}
		}
	}
	return result;
}

CMatrix3 & CMatrix3::Add(const CMatrix3 & _rA, const CMatrix3 & _rB, CMatrix3 & _rResult)
{
	float matrixAEl;
	float matrixBEl;
	float sum;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixAEl = _rA.GetElement(i, j);
			matrixBEl = _rB.GetElement(i, j);
			sum = matrixAEl + matrixBEl;
			_rResult.SetElement(i, j, sum);
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Subtract(const CMatrix3 & _rA, const CMatrix3 & _rB, CMatrix3 & _rResult)
{
	float matrixAEl;
	float matrixBEl;
	float difference;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixAEl = _rA.GetElement(i, j);
			matrixBEl = _rB.GetElement(i, j);
			difference = matrixAEl - matrixBEl;
			_rResult.SetElement(i, j, difference);
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Multiply(float _fScalar, const CMatrix3 & _rA, CMatrix3 & _rResult)
{
	float matrixAEl;
	float quotient;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixAEl = _rA.GetElement(i, j);
			quotient = _fScalar * matrixAEl;
			_rResult.SetElement(i, j, quotient);
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Multiply(const CMatrix3 & _rA, const CMatrix3 & _rB, CMatrix3 & _rResult)
{
	float matrixAEl;
	float matrixBEl;
	float matMul = 0.0f;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				matrixAEl = _rA.GetElement(i, k);
				matrixBEl = _rB.GetElement(k, j);

				matMul += matrixAEl * matrixBEl;
				_rResult.SetElement(i, j, matMul);
			}
		}
	}
	return _rResult;
}

CMatrix3 & CMatrix3::Transpose(const CMatrix3 & _rA, CMatrix3 & _rResult)
{
	float matrixAEl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixAEl = _rA.GetElement(i, j);
			_rResult.SetElement(j, i, matrixAEl);
		}
	}
	return _rResult;
}

void CMatrix3::displayMatrix()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "\n";
		for (int j = 0; j < 3; j++)
		{
			cout << m_fMatrix[i][j] << " ";
		}
	}
}
