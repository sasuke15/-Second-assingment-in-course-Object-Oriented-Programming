#pragma once
#include <iostream>
using namespace std;

class Matrix
{

public:

	Matrix(int hight, int leangh);
	Matrix(const Matrix& mat);
	~Matrix();

	double * operator[](int i);
	const double * operator[](int i) const;

	Matrix operator +(const Matrix&r) const;
	Matrix operator -(const Matrix&r) const;
	Matrix operator *(const Matrix&r) const;
	Matrix operator =(const Matrix&r);

	void operator +=(const Matrix&r);
	void operator -=(const Matrix&r);
	void operator *=(const Matrix&r);

	Matrix operator -()const;
	Matrix operator *(double c) const;

	void operator *=(double c);

	friend ostream& operator<<(ostream& Out, const Matrix& C);

private:

	int hight;
	int leangh;
	double ** m_a;

};

ostream& operator<<(ostream&, const Matrix&);
Matrix operator * (double left, const Matrix& C);
