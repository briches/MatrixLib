// Built to test the MatrixLib library I'm writing, for use in the quadcopter project.
// Uses a custom type for matrices,

#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "OSQ_MatrixLib.h"

using namespace std;

Matrix A(3,3);
Matrix B(2,1);
Matrix dest(3,3);

int main()
{
	//int error = matrixMul(&dest, &A, &B);
	//int error = cholInv(&dest, &A);
	//	cout << "A: " << endl;
	//	for(int i = 0; i < (A.rows * A.cols); i++)
	//	{
	//		cout << A.pdata[i] << endl;
	//	}
	//
	//	cout << "\nDest: " << endl;
	//	for(int i = 0; i < (dest.rows * dest.cols); i++)
	//	{
	//		cout << dest.pdata[i] << endl;
	//	}
	//
	//	cout << "\nError code: " << error;

	int n = 3, foundSets = 1;
	int* set = new int[n];
	int fact = 1;

	for(int i = 0; i < n; i++)
	{
		fact *= (n-i);
		set[i] = i;
	}

	int* checkedSets = (int*)malloc(fact * n * sizeof(int));

	while(foundSets < fact)
	{
		int switchSpot, value;
		foundSets++;
	}

	free(checkedSets); // Clear that shit up
	return 1;
}
