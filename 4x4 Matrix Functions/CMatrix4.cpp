#include "CMatrix4.h"

CMatrix4::CMatrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_fMatrix[i][j] = 0;
		}
	}
}

CMatrix4::~CMatrix4()
{
}

void CMatrix4::SetElement(int _iX, int _iY, float _fValue)
{
	m_fMatrix[_iX][_iY] = _fValue;
}

float CMatrix4::GetElement(int _iX, int _iY) const
{
	return m_fMatrix[_iX][_iY];
}

CMatrix4 & CMatrix4::Identity(CMatrix4 & _rResult)
{
	//1st row
	_rResult.SetElement(0, 0, 1);
	_rResult.SetElement(0, 1, 0);
	_rResult.SetElement(0, 2, 0);
	_rResult.SetElement(0, 3, 0);

	//2nd row
	_rResult.SetElement(1, 0, 0);
	_rResult.SetElement(1, 1, 1);
	_rResult.SetElement(1, 2, 0);
	_rResult.SetElement(1, 3, 0);

	//3rd row
	_rResult.SetElement(2, 0, 0);
	_rResult.SetElement(2, 1, 0);
	_rResult.SetElement(2, 2, 1);
	_rResult.SetElement(2, 3, 0);

	//4th row
	_rResult.SetElement(3, 0, 0);
	_rResult.SetElement(3, 1, 0);
	_rResult.SetElement(3, 2, 0);
	_rResult.SetElement(3, 3, 1);
	return _rResult;
}

CMatrix4 & CMatrix4::Zero(CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.SetElement(i, j, 0);
		}
	}

	return _rResult;
}

bool CMatrix4::Equals(const CMatrix4 & _rA, const CMatrix4 & _rB)
{
	bool result = true;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
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

CMatrix4 & CMatrix4::Add(const CMatrix4 & _rA, const CMatrix4 & _rB, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] + _rB.m_fMatrix[i][j];
		}
	}
	return _rResult;
}

CMatrix4 & CMatrix4::Subtract(const CMatrix4 & _rA, const CMatrix4 & _rB, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] - _rB.m_fMatrix[i][j];
		}
	}
	return _rResult;
}

CMatrix4 & CMatrix4::Multiply(float _fScalar, const CMatrix4 & _rA, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] * _fScalar;
		}
	}
	return _rResult;
}

CMatrix4 & CMatrix4::Multiply(const CMatrix4 & _rA, const CMatrix4 & _rB, CMatrix4 & _rResult)
{
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < 4; i++)
		{
			int tmp = _rA.m_fMatrix[i][k];
			for (int j = 0; j < 4; j++)
			{
				_rResult.m_fMatrix[i][j] += tmp * _rB.m_fMatrix[k][j];
			}
		}
	}

	return _rResult;
}

CMatrix4 & CMatrix4::Transpose(const CMatrix4 & _rA, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[j][i];
		}
	}
	return _rResult;
}

MVector3 & CMatrix4::ScaleVector(float _scaleX, float _scaleY, float _scaleZ, MVector3 & _vec, MVector3 & _resultntV)
{
	CMatrix4 scaleMatrix;
	scaleMatrix.SetElement(0, 0, _scaleX);
	scaleMatrix.SetElement(1, 1, _scaleY);
	scaleMatrix.SetElement(2, 2, _scaleZ);
	scaleMatrix.SetElement(3, 3, 1);


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_resultntV.matrixForm[i] += (scaleMatrix.m_fMatrix[i][j] * _vec.matrixForm[i]);
		}
	}

	return _resultntV;
}

MVector3 & CMatrix4::TranslateVector(float _transX, float _transY, float _transZ, MVector3 & _vec, MVector3 & _resultntV)
{
	CMatrix4 transMatrix;
	transMatrix = Identity(transMatrix);
	transMatrix.SetElement(0, 3, _transX);
	transMatrix.SetElement(1, 3, _transY);
	transMatrix.SetElement(2, 3, _transZ);
	transMatrix.SetElement(3, 3, 1);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_resultntV.matrixForm[i] = (transMatrix.m_fMatrix[i][j] + _vec.matrixForm[i]);
		}
	}

	return _resultntV;
}

MVector3 & CMatrix4::RotateZ(float _angle, MVector3 & _vec, MVector3 & _resultntV)
{
	CMatrix4 rotateMatrix;
	rotateMatrix.SetElement(0, 0, COS(_angle));
	rotateMatrix.SetElement(0, 1, (-1 * (SIN(_angle))));
	rotateMatrix.SetElement(1, 0, SIN(_angle));
	rotateMatrix.SetElement(1, 1, (COS(_angle)));
	rotateMatrix.SetElement(2, 2, 1);
	rotateMatrix.SetElement(3, 3, 1);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_resultntV.matrixForm[i] += (rotateMatrix.m_fMatrix[i][j] * _vec.matrixForm[i]);
		}
	}

	return _resultntV;
}

MVector3 & CMatrix4::RotateY(float _angle, MVector3 & _vec, MVector3 & _resultntV)
{
	CMatrix4 rotateMatrix;
	rotateMatrix.SetElement(0, 0, COS(_angle));
	rotateMatrix.SetElement(0, 2, SIN(_angle));
	rotateMatrix.SetElement(1, 1, 1);
	rotateMatrix.SetElement(2, 0, (-1 * (SIN(_angle))));
	rotateMatrix.SetElement(2, 2, COS(_angle));
	rotateMatrix.SetElement(3, 3, 1);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_resultntV.matrixForm[i] += (rotateMatrix.m_fMatrix[i][j] * _vec.matrixForm[i]);
		}
	}

	return _resultntV;
}

MVector3 & CMatrix4::RotateX(float _angle, MVector3 & _vec, MVector3 & _resultntV)
{
	CMatrix4 rotateMatrix;
	rotateMatrix.SetElement(0, 0, 1);
	rotateMatrix.SetElement(1, 1, COS(_angle));
	rotateMatrix.SetElement(1, 2, (-1 * (SIN(_angle))));
	rotateMatrix.SetElement(2, 1, SIN(_angle));
	rotateMatrix.SetElement(2, 2, COS(_angle));
	rotateMatrix.SetElement(3, 3, 1);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_resultntV.matrixForm[i] += (rotateMatrix.m_fMatrix[i][j] * _vec.matrixForm[i]);
		}
	}

	return _resultntV;
}

void CMatrix4::displayMatrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << m_fMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}
