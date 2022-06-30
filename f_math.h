#ifndef H_MATH
#define H_MATH
	#include <math.h>
	#include <cstdio>
	#include <cstdlib>
	#include <ctime>
	#include "Matrix.h"

	typedef struct tuplus tuplus;
	struct tuplus
	{
		Matrix* x;
		Matrix* y;
	};

	typedef struct point point;
	struct point
	{
		int x;
		int y;
	};

	Matrix sigmoid(Matrix x);
	Matrix sigmoidPrime(Matrix x);
	void shuffle(tuplus* miniBatch, int miniBatch_size);

#endif
