#include <cstdlib>
#include <iostream>

#include "Matrix.h"
#include "f_math.h"

class Azdviw
{
private:
	int m_nbLayers;
	int* m_sizes;
	Matrix **biases;
	Matrix **weights;

public:
	Azdviw(int* sizes, int nbLayers);
	Azdviw(Azdviw const& source);
	Matrix feedForward(Matrix a);
	int getParsesOutput(Matrix &input, Matrix &result);
	void evoluate(int generations, int promo_size, int nb_majorant, double lambda);
	void selection(Azdviw **promo, int promo_size, int *majors, int nb_majorant);
	Azdviw mutate(double lambda);
	void saveAzdviw(Azdviw* myAzd);
	Azdviw& operator=(Azdviw const& o_az);
	~Azdviw();
};
