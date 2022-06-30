#include "Azdviw.h"

Azdviw::Azdviw(int* sizes, int nbLayers) {

	m_sizes = sizes;
	m_nbLayers = nbLayers;
	biases = new Matrix*[nbLayers-1];
	weights = new Matrix*[nbLayers-1];

	for (int i = 0; i < nbLayers-1; i++) {

		biases[i] = new Matrix(1, sizes[i+1]);
		weights[i] = new Matrix(sizes[i], sizes[i+1]);

		biases[i]->rand_feel();
		//printf("==\n");
		weights[i]->rand_feel();

	}

}

Azdviw::Azdviw(Azdviw const& source) {

	m_sizes = source.m_sizes;
	m_nbLayers = source.m_nbLayers;
	biases = new Matrix*[source.m_nbLayers-1];
	weights = new Matrix*[source.m_nbLayers-1];

	for (int i = 0; i < m_nbLayers-1; i++) {
		*(biases[i]) = *(source.biases[i]);
		*(weights[i]) = *(source.weights[i]);
	}

}


Matrix Azdviw::feedForward(Matrix a){

	for (int i = 0; i < m_nbLayers-1; i++){
		a = sigmoid(( *weights[i] * a ) + *biases[i]);
	}
	return a;
}

int Azdviw::parseInput(int *brut_input, point tete){
	// 8 neurones qui vont s'activer comme tel:
	/*
			un neurone gere le danger au nord, plus un obstacle est proche moins
			il sera activer
			de meme pour les 3 autres neurones et points cardinaux
			un meme proceder est effectué pour les 4 autres neurones pour traiter
			le fruit
	*/

	Matrix input(1,8);
	input.setNull();

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++) {//danger par rapport au reste du corp
			if ( grille[i][j] > 0 ) {
				input.setCell();
			}
		}



	return max;
}

int Azdviw::getParsesOutput(int *brut_input,point tete){
	Matrix result = feedForward(parse(brut_input, tete));

	int max = 0;
	for (int j = 1; j < m_sizes[m_nbLayers-1]; j++)
		if ( result.getCell(0, j) >  result.getCell(0, max) )
			max = j;
	return max;
}

void Azdviw::evoluate(int generations, int promo_size, int nb_majorant, double lambda){

	Azdviw **promo = new Azdviw*[promo_size];
	int *majors = new int[nb_majorant];

	int k;

	for (int i = 0; i < promo_size; i++)
		promo[i] = new Azdviw(m_sizes, m_nbLayers);//on remplie la promo

	for (int i = 0; i < generations; i++) {//pour chaque gen
		printf("Generation %d : \n", i+1);
		selection(promo, promo_size, majors, nb_majorant);

		k = -1;
		for (int j = 0; j < promo_size; j++) {
			if ( j % nb_majorant == 0 )
				k++;
			*promo[j] = promo[majors[k]]->mutate(lambda);
		}

	}

	saveAzdviw(promo[majors[0]]);

}

void Azdviw::saveAzdviw(Azdviw* myAzd) {

}

void Azdviw::selection(Azdviw **promo, int promo_size, int *majors, int nb_majorant){
	int indice(0),
			result(0);

	int *scores = new int[nb_majorant];

	for (int i = 0; i < nb_majorant; i++){
		majors[i] = 0;
		scores[i] = 0;
	}

	for (int i = 0; i < promo_size; i++) {
		result = play(*promo[i], false);
		indice = 0;

		while ( result < scores[indice] )
			indice++;
		if ( indice < 10 ){
			scores[indice] = result;
			majors[indice] = i;
		}

	}
}

Azdviw Azdviw::mutate(double lambda){

	Azdviw new_Azdviw(m_sizes, m_nbLayers);


	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::normal_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < new_Azdviw.m_nbLayers - 1; i++) {
		for (int j = 0; j < new_Azdviw.biases[i]->getLength(); j++)
			for (int k = 0; k < new_Azdviw.biases[i]->getHeight(); k++)
				new_Azdviw.biases[i]->setCell( lambda * distribution(generator) + biases[i]->getCell(j, k), j, k);

		for (int j = 0; j < new_Azdviw.weights[i]->getLength(); j++)
			for (int k = 0; k < new_Azdviw.weights[i]->getHeight(); k++)
				new_Azdviw.weights[i]->setCell( lambda * distribution(generator) + weights[i]->getCell(j, k), j, k);
	}

	return new_Azdviw;//Vertifier si on fait une copie correvte du pointeur
}

Azdviw& Azdviw::operator=(Azdviw const& o_az){

	for (int i = 0; i < m_nbLayers-1; i++) {
		delete biases[i];
		delete weights[i];
	}
	delete biases;
	delete weights;

	m_sizes = o_az.m_sizes;
	m_nbLayers = o_az.m_nbLayers;

	biases = new Matrix*[o_az.m_nbLayers-1];
	weights = new Matrix*[o_az.m_nbLayers-1];


	for (int i = 0; i < o_az.m_nbLayers-1; i++) {
		biases[i] = new Matrix(*(o_az.biases[i]));
		weights[i] = new Matrix(*(o_az.weights[i]));
	}
	//printf("GUT ?\n");
	return *this;
}

Azdviw::~Azdviw(){
	//delete m_sizes;
	for (int i = 0; i < m_nbLayers-1; i++) {
		delete biases[i];
		delete weights[i];
	}
	delete biases;
	delete weights;
}
