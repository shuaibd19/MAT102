#include <iostream>
#include "CMatrix3.h"
#include "CMatrix4.h"
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	
	CMatrix4 matrMath;

	MVector3 pointOnScreen;
	MVector3 result;

	pointOnScreen.matrixForm[0] = 2;
	pointOnScreen.matrixForm[1] = 2;
	pointOnScreen.matrixForm[2] = 2;
	pointOnScreen.matrixForm[3] = 1;

	result.matrixForm[0] = 0;
	result.matrixForm[1] = 0;
	result.matrixForm[2] = 0;
	result.matrixForm[3] = 1;

	cout << "point on the screen: x: " << pointOnScreen.matrixForm[0] << " y: " << pointOnScreen.matrixForm[1]
		<< " z: " << pointOnScreen.matrixForm[2] << endl;

	cout << "let's translate this SOB!" << endl;

	float transX = 1;
	float transY = 2;
	float transZ = 5;

	result = matrMath.TranslateVector(transX, transY, transZ, pointOnScreen, result);

	//result = matrMath.RotateZ(90.0f, pointOnScreen, result);

	cout << "point on the screen: x: " << result.matrixForm[0] << " y: " << result.matrixForm[1]
		<< " z: " << result.matrixForm[2] << endl;


	return 0;
}