/* Matrix library for implementing matrix math with low resource consumption */

#ifndef OSQ_MATRIXLIB_H_INCLUDED
#define OSQ_MATRIXLIB_H_INCLUDED


#if ARDUINO > 100
	#include "Arduino.h"
#endif

typedef struct Matrix_t
{
	// Matrices are addressed in row major format, ie: Matrix(row, col) = a;

	int8_t rows, cols;

	float* pdata;

	Matrix_t(int8_t nrows, int8_t ncols); // Constructor

	~Matrix_t(); // Destructor

}Matrix;

Matrix_t :: Matrix_t(int8_t nrows, int8_t ncols)
{
	rows = nrows;
	cols = ncols;
	pdata =  (float*) malloc(rows * cols * sizeof(float));
};

Matrix_t :: ~Matrix_t()
{
	free(pdata);
};


#endif // OSQ_MATRIXLIB_H_INCLUDED
