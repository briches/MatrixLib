// Built to test the MatrixLib library I'm writing, for use in the quadcopter project.
// Uses a custom type for matrices,

#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "OSQ_MatrixLib.h"

using namespace std;

Matrix A(3,3);
Matrix B(3,3);
Matrix dest(3,3);

int main()
{
	A.set(0,0,2);
	A.set(0,1,1);
	A.set(0,2,0);
	A.set(1,0,1);
	A.set(1,1,2);
	A.set(1,2,1);
	A.set(2,0,0);
	A.set(2,1,1);
	A.set(2,2,2);


	//int error = matrixMul(&dest, &A, &B);
	int error = cholInv(&dest, &A);

	cout << "\nInverse of A:" << endl;
	for(int i = 0; i < (dest.rows * dest.cols); i++)
	{
		cout << dest.pdata[i] << endl;
	}

	cout << "\nError code: " << error;

	return 1;
}
