/* Matrix library for implementing matrix math with low resource consumption */

/**//** Included functions: /**//**/
// typedef Matrix_t
// constructor Matrix_t(int nrows, int ncols)
// destructor ~Matrix_t()
// void Matrix_t :: set(int row, int col, float value)

#ifndef OSQ_MATRIXLIB_H_INCLUDED
#define OSQ_MATRIXLIB_H_INCLUDED

#include <stdlib.h>
#include <iostream>
using namespace std;

#if ARDUINO > 100
	#include "Arduino.h"
#endif

#define NO_ERROR				0x00
#define MATRIX_INPUT_DIM_ERR	0x02
#define MATRIX_OUTPUT_DIM_ERR	0x04

typedef struct Matrix_t
{
	// Matrices are addressed in row major format, ie: Matrix(row, col) = a;

	int rows, cols;
	float* pdata;

	void set(int row, int col, float value);

	Matrix_t(int nrows, int ncols); // Constructor


	~Matrix_t(); // Destructor

}Matrix;

void Matrix_t :: set(int row, int col, float value)
{
	pdata[row*cols + col] = value;
};


/* Constructor */
Matrix_t :: Matrix_t(int nrows, int ncols)
{
	rows = nrows;
	cols = ncols;
	pdata =  (float*) malloc(rows * cols * sizeof(float));
	for(int i = 0; i< rows*cols; i++)
	{
		pdata[i] = 0;
	}
};

/* Destructor */
Matrix_t :: ~Matrix_t()
{
	free(pdata);
};

uint8_t matrixMul(Matrix_t* dest, Matrix_t* A, Matrix_t* B)
{
	/** uint8_t error = matrixMul(&dest, &A, &B); **/
	/** Returns A * B **/
	// If A is an m x n matrix, and
	// if B is an n x b matrix, then
	// dest must be an m x b matrix.

	// Check input dimensions.
	if(A->cols != B->rows) return MATRIX_INPUT_DIM_ERR;

	// Check output matrix dimensions
	if((dest->rows != A->rows) && (dest->cols != B->cols)) return MATRIX_OUTPUT_DIM_ERR;

	// Multply
	for(int colB = 0; colB < B->cols; colB++) // Column in B
	{
		for(int rowA = 0; rowA < A->rows; rowA++) // Row A
		{
			// Element-wise multiplication and sum in this ROW of A and COL of B
			for(int i = 0; i < A->cols; i++) // Number of cols in B
			{
				dest->pdata[colB + rowA] += A->pdata[rowA * A->cols + i] * B->pdata[colB * B->rows + i];
			}
		}
	}
	return NO_ERROR;

};


#endif // OSQ_MATRIXLIB_H_INCLUDED
