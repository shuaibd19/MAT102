#include <iostream>
#include "CMatrix3.h"
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	CMatrix3 matrixMath;

	MVector2 pointOnScreen;
	MVector2 result;

	float angle = 360.0f;//this is in degrees

	cout << "the point on the screen is: x: " << pointOnScreen.matrixForm[0] << " y: " << pointOnScreen.matrixForm[1] << endl;
	cout << "lets translate its x coordinate by 2 and y coordinate by 2\n";

	result.matrixForm[0] = 0;
	result.matrixForm[1] = 0;

	result = matrixMath.TranslateVector(2, 2, pointOnScreen, result);

	cout << "the point on the screen is: x: " << result.matrixForm[0] << " y: " << result.matrixForm[1] << endl;

	/*cout << "let's scale this SOB! BY 10!\n";

	result = matrixMath.ScaleVector(10, 10, result, result);

	cout << "the point on the screen is: x: " << result.matrixForm[0] << " y: " << result.matrixForm[1] << endl;*/

	cout << "let's rotate this SOB! BY 360 degrees!\n";

	result = matrixMath.RotateVector(angle, result, result);

	cout << "the point on the screen is: x: " << result.matrixForm[0] << " y: " << result.matrixForm[1] << endl;


	return 0;
}