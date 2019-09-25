#include <iostream>
#include "CMatrix3.h"
#include <time.h>
using namespace std;

int main()
{
	srand(time(0));
	cout << "Setting up zero matrix:\n";
	CMatrix3 matrix;
	matrix.displayMatrix();
	cout << "\nSetting up identity matrix:\n";
	matrix.Identity(matrix);
	matrix.displayMatrix();

	CMatrix3 matrix2;
	bool isEqual = false;
	cout << "\nMatrix 1:\n";
	matrix.displayMatrix();
	cout << "\nMatrix 2:\n";
	matrix2.displayMatrix();
	cout << "\nChecking for matrix equality...:\n";
	isEqual = matrix.Equals(matrix, matrix2);
	if (!isEqual)
	{
		cout << "\nThe two vectors are not equal\n";
	}
	else
	{
		cout << "\nHuzza! The two vectors are equal!\n";
		
	}

	cout << "\Making Matrix 1 a zero matrix:\n";
	matrix = matrix.Zero(matrix);
	cout << "\nMatrix 1:\n";
	matrix.displayMatrix();
	cout << "\nMatrix 2:\n";
	matrix2.displayMatrix();
	cout << "\nChecking for matrix equality...:\n";
	isEqual = matrix.Equals(matrix, matrix2);
	if (!isEqual)
	{
		cout << "\nThe two vectors are not equal\n";
	}
	else
	{
		cout << "\nHuzza! The two vectors are equal!\n";

	}

	CMatrix3 add1, add2, result, result2, result3, result4, result5;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			add1.SetElement(i, j, rand() % 20);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			add2.SetElement(i, j, (rand() % 20)*(-1));
		}
	}

	cout << "\t\t-------------------------------------------------------\n";
	cout << "Now lets test addition!\n";
	cout << "Matrix 1:\n";
	add1.displayMatrix();
	cout << endl;
	cout << "Matrix 2:\n";
	add2.displayMatrix();
	cout << endl;
	result = result.Add(add1, add2, result);
	cout << "Result is:\n";
	result.displayMatrix();

	cout << "\t\t-------------------------------------------------------\n";
	cout << "Now lets test Subtraction!\n";
	cout << "Matrix 1:\n";
	add1.displayMatrix();
	cout << endl;
	cout << "Matrix 2:\n";
	add2.displayMatrix();
	cout << endl;
	result2 = result2.Subtract(add1, add2, result2);
	cout << "Result is:\n";
	result2.displayMatrix();

	cout << "\t\t-------------------------------------------------------\n";
	cout << "Now lets test Scalar Multiplication!\n";
	cout << "Matrix 1:\n";
	add1.displayMatrix();
	cout << endl;
	float scalar = 2.0f;
	cout << "Scalar value is:\n";
	cout << scalar;
	cout << endl << endl;
	result3 = result3.Multiply(scalar, add1, result3);
	cout << "Result is:\n";
	result3.displayMatrix();

	cout << "\t\t-------------------------------------------------------\n";
	cout << "Now lets test Matrix Multiplication!\n";
	cout << "Matrix 1:\n";
	add1.displayMatrix();
	cout << endl;
	cout << "Matrix 2:\n";
	add2.displayMatrix();
	cout << endl;
	result4 = result4.Multiply(add1, add2, result4);
	cout << "Result is:\n";
	result4.displayMatrix();

	cout << "\t\t-------------------------------------------------------\n";
	cout << "Now lets test Matrix Transposition!\n";
	cout << "Matrix 1:\n";
	add1.displayMatrix();
	cout << endl;
	result5 = result5.Transpose(add1, result5);
	cout << "Result is:\n";
	result5.displayMatrix();
	return 0;
}