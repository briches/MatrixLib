// Built to test the MatrixLib library I'm writing, for use in the quadcopter project.
// Uses a custom type for matrices,

#include <stdlib.h>
#include <iostream>

#include "OSQ_MatrixLib.h"

using namespace std;

Matrix myMatrix(2,2);

int main()
{

	cout << "Hello World!" << endl;


	myMatrix.~Matrix();

	return 1;
}
