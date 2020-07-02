#include"mat.h"

Matrix::Matrix(int hight, int leangh)
{

	this->hight = hight;

	this->leangh = leangh;

	m_a = new double *[hight];

	for (int i = 0; hight > i; i++)
	{
		m_a[i] = new double[leangh];

		for (int j = 0; leangh > j; j++)
			(*this)[i][j] = 0;

	}

}

Matrix::Matrix(const Matrix& mat)
{

	this->hight = mat.hight;

	this->leangh = mat.leangh;

	m_a = new double *[hight];

	for (int i = 0; hight > i; i++)
	{
		m_a[i] = new double[leangh];

		for (int j = 0; leangh > j; j++)
			(*this)[i][j] = mat[i][j];

	}
}

Matrix::~Matrix()
{

	for (int i = 0; hight > i; i++)
		delete[] m_a[i];

	delete[] m_a;

}

double * Matrix::operator[](int i)
{

	return m_a[i];

}

const double * Matrix::operator[](const int i) const
{

	return m_a[i];

}

Matrix Matrix::operator +(const Matrix&r) const
{

	if (hight == r.hight &&  leangh == r.leangh)
	{

		Matrix m(*this);

		for (int i = 0; hight > i; i++)
			for (int j = 0; leangh > j; j++)
				m[i][j] = (*this)[i][j] + r[i][j];

		return m;

	}

}

Matrix Matrix::operator =(const Matrix&r)
{
	for (int i = 0; hight > i; i++)
		for (int j = 0; leangh > j; j++)
			(*this)[i][j] = r[i][j];

	return *this;
}

Matrix Matrix::operator -(const Matrix&r) const
{

	return Matrix((*this) + (-r));

}

Matrix Matrix::operator *(const Matrix&r) const
{

	if (hight == r.leangh)
	{

		Matrix m(r.hight, leangh);

		for (int i = 0; r.hight > i; i++)
			for (int j = 0; leangh > j; j++)
				for (int k = 0; hight > k; k++)
				{

					if (k == 0)
					{
						if ((*this)[k][j] == 0 || r[i][k] == 0)
							m[i][j] = 0;

						else
							m[i][j] = (*this)[k][j] * r[i][k];
					}

					else
					{
						if (m[i][j] + (*this)[k][j] + r[i][k] == 0)
							m[i][j] = 0;

						else
							m[i][j] += (*this)[k][j] * r[i][k];
					}

				}

		return m;

	}

}

void Matrix::operator +=(const Matrix&r)
{

	(*this) = (*this) + r;

}

void Matrix::operator -=(const Matrix&r)
{

	(*this) = (*this) - r;

}

void Matrix::operator *=(const Matrix&r)
{

	(*this) = (*this) * r;

}

Matrix Matrix::operator -()const
{

	return (*this) * -1;

}

Matrix Matrix::operator *(double c) const
{

	Matrix m(*this);

	for (int i = 0; hight > i; i++)
		for (int j = 0; leangh > j; j++)
			if (c == 0 || m[i][j] == 0)
				m[i][j] = 0;
			else
				m[i][j] *= c;

	return m;

}

void Matrix::operator *=(double c)
{

	(*this) = (*this) * c;

}

ostream& operator<<(ostream& Out, const Matrix& C)
{

	for (int i = 0; C.hight > i; i++)
	{
		for (int j = 0; C.leangh > j; j++)
			Out << C[i][j] << " ";

		Out << endl;
	}

	return Out;

}

Matrix operator * (double left, const Matrix& C)
{

	return C * left;

}
