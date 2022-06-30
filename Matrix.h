#ifndef H_MATRIX
#define H_MATRIX

	#include <iostream>
	#include <chrono>
	#include <random>


	class Matrix
	{
	private:
		int m_length;
		int m_height;

		double** m_matrix;


	public:
		Matrix(int l=0, int h=0);
		Matrix(Matrix const& o_ma);
		void rand_feel();
		void setNull();
		void print() const;
		int getHeight() const;
		int getLength() const;
		double getCell(int p_l, int p_h) const;
		void setCell(double value, int p_l, int p_h);	
		Matrix transpose() const;	
		Matrix add(Matrix const& o_ma);
		Matrix substract(Matrix const& o_ma);
		Matrix dot(Matrix const& o_ma);
		Matrix harmada(Matrix const& o_ma);
		Matrix nbMultiplication(double const number);
		Matrix& operator=(Matrix const& ma2);
		~Matrix();
		
	};

	Matrix operator+(Matrix ma1, Matrix const& ma2);
	Matrix operator-(Matrix ma1, Matrix const& ma2);
	Matrix operator*(Matrix ma1, Matrix const& ma2);
	Matrix operator*(Matrix ma1, double number);
	Matrix operator%(Matrix ma1, Matrix const& ma2);

#endif

