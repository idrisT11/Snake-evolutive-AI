#include "f_math.h"

Matrix sigmoid(Matrix x){
	for (int i = 0; i < x.getLength(); i++)
		for (int j = 0; j < x.getHeight(); j++)
			x.setCell( 1/( 1 + exp(-x.getCell(i, j))) , i, j);
	return x;	
}

Matrix sigmoidPrime(Matrix x){
	for (int i = 0; i < x.getLength(); i++)
		for (int j = 0; j < x.getHeight(); j++)
			x.setCell( exp(-x.getCell(i, j)) / ((1+exp(-x.getCell(i, j))) * (1+exp(-x.getCell(i, j)))) , i, j);		
	return x;
}

void shuffle(tuplus* batch, int batch_size){
	int rand_indice;
	tuplus tmp;

	for (int i = 0; i < batch_size; i++) {
		rand_indice = rand() % batch_size;

		tmp = batch[i];
		batch[i] = batch[rand_indice];
		batch[rand_indice] = tmp;

	}

}

