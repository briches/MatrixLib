// Built to test the MatrixLib library I'm writing, for use in the quadcopter project.
// Uses a custom type for matrices,

#include <stdlib.h>
#include <iostream>

#include "OSQ_MatrixLib.h"

using namespace std;

Matrix A(2,2);
Matrix B(2,1);
Matrix dest(2,1);

int main()
{

	A.set(0,0,1);
	A.set(0,1,0);
	A.set(1,0,0);
	A.set(1,1,1);

	B.set(0,0,5);
	B.set(1,0,6);

	uint8_t error = matrixMul(&dest, &A, &B);

	cout << " Error code: " << error << endl;

	A.~Matrix();
	B.~Matrix();
	dest.~Matrix();

	return 1;
}
