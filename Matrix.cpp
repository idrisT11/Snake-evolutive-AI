/*
============================================================
	Methode of the Matrix' Class :
============================================================
*/

#include "Matrix.h"
//CONSTRUCTORS==============================================================
Matrix::Matrix(int l, int h){
	m_length = l;
	m_height = h;

	m_matrix = new double*[l];
	for (int i = 0; i < l; i++)
		m_matrix[i] = new double[h];

}
Matrix::Matrix(Matrix const& o_ma){
	m_length = o_ma.m_length;
	m_height = o_ma.m_height;

	m_matrix = new double*[m_length];
	for (int i = 0; i < m_length; i++)
		m_matrix[i] = new double[m_height];

	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			m_matrix[i][j] = o_ma.m_matrix[i][j];
}
//===========================================================================
int Matrix::getLength() const{
	return m_length;
}
int Matrix::getHeight() const{
	return m_height;
}
double Matrix::getCell(int p_l, int p_h) const{
	if ( p_l < m_length && p_h < m_height )
		return m_matrix[p_l][p_h];
	else
	{
		printf("Problemexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		return 0;
	}
}
void Matrix::setCell(double value, int p_l, int p_h){
	//std::cout << "Matrix : " << value << '\n';
	if ( p_l < m_length && p_h < m_height )
		m_matrix[p_l][p_h] = value;
	else
		printf("Problemexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
}
//===========================================================================
void Matrix::rand_feel(){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator(seed);
  	std::normal_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			m_matrix[i][j] = distribution(generator);
}

void Matrix::setNull(){
	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			m_matrix[i][j] = 0;
}

Matrix Matrix::transpose() const{
	Matrix new_matrix(m_height, m_length);

	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			new_matrix.m_matrix[j][i] = m_matrix[i][j];

	return new_matrix;
}

Matrix Matrix::add(Matrix const& o_ma){
	Matrix new_matrix(m_length, m_height);
	if ( (o_ma.m_height != m_height) || (o_ma.m_length != m_length )){
		printf("Addition Problemexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("this L:%d H:%d ||other L: %d H:%d  \n", m_length, m_height, o_ma.m_length, o_ma.m_height);
	}
	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			new_matrix.m_matrix[i][j] = m_matrix[i][j] + o_ma.m_matrix[i][j];

	return new_matrix;

}

Matrix Matrix::substract(Matrix const& o_ma){
	Matrix new_matrix(m_length, m_height);
	if ( (o_ma.m_height != m_height) || (o_ma.m_length != m_length )){
		printf("Soustarction Problemexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("this L:%d H:%d ||other L: %d H:%d  \n", m_length, m_height, o_ma.m_length, o_ma.m_height);

	}
	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			new_matrix.m_matrix[i][j] = m_matrix[i][j] - o_ma.m_matrix[i][j];

	return new_matrix;

}

Matrix Matrix::harmada(Matrix const& o_ma){
	Matrix new_matrix(m_length, m_height);
	if ( (o_ma.m_height != m_height) || (o_ma.m_length != m_length )){
		printf("harmada Problemexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("this L:%d H:%d ||other L: %d H:%d  \n", m_length, m_height, o_ma.m_length, o_ma.m_height);
	}
	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			new_matrix.m_matrix[i][j] = m_matrix[i][j] * o_ma.m_matrix[i][j];

	return new_matrix;

}

Matrix Matrix::nbMultiplication(double const number){
	Matrix new_matrix(m_length, m_height);

	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			new_matrix.m_matrix[i][j] = m_matrix[i][j] * number;

	return new_matrix;
}

Matrix Matrix::dot(Matrix const& o_ma){
	double tmp(0);

	if ( o_ma.m_height != m_length ){
		printf("Dot Problemexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf(" this m_length : %d other m_height : %d :\n", m_length, o_ma.m_height );
	}

	Matrix new_matrix(o_ma.m_length, m_height);
	//il faut que la largeur de la matrice 1 soit egal a la hauteur de la matrice 2
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < o_ma.m_length; j++)
		{
			for (int k = 0; k < m_length; k++)
				tmp+= o_ma.m_matrix[j][k] * m_matrix[k][i];

			new_matrix.m_matrix[j][i] = tmp;
			tmp = 0;
		}
	return new_matrix;
}

void Matrix::print() const{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_length; j++)
			std::cout << m_matrix[j][i] << " | ";
		std::cout << "\n";
	}
	printf("%d\n", m_matrix);
	std::cout << "\n\n";

}
Matrix::~Matrix(){
	for (int i = 0; i < m_length; i++)
		delete m_matrix[i];
	delete m_matrix;
}
//OPERATOR==========================================================================
Matrix operator+(Matrix ma1, Matrix const& ma2){
	Matrix new_matrix(ma1.add(ma2));

	return new_matrix;
}

Matrix operator-(Matrix ma1, Matrix const& ma2){
	Matrix new_matrix(ma1.substract(ma2));

	return new_matrix;
}

Matrix operator*(Matrix ma1, Matrix const& ma2){
	Matrix new_matrix(ma1.dot(ma2));

	return new_matrix;
}

Matrix operator*(Matrix ma1, double number){
	Matrix new_matrix(ma1.nbMultiplication(number));

	return new_matrix;
}


Matrix operator%(Matrix ma1, Matrix const& ma2){
	Matrix new_matrix(ma1.harmada(ma2));

	return new_matrix;
}

Matrix& Matrix::operator=(Matrix const& o_ma){
	for (int i = 0; i < m_length; i++)
		delete m_matrix[i];
	delete m_matrix;

	m_length = o_ma.m_length;
	m_height = o_ma.m_height;

	m_matrix = new double*[m_length];
	for (int i = 0; i < m_length; i++)
		m_matrix[i] = new double[m_height];

	for (int i = 0; i < m_length; i++)
		for (int j = 0; j < m_height; j++)
			m_matrix[i][j] = o_ma.m_matrix[i][j];

	return *this;
}
