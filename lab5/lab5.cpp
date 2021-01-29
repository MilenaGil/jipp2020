#include <stdlib.h>
#include <iostream>
#include <locale.h>

using namespace std;

class Matrix
{

private:
	int N, M;   //N wiersze, M kolumny
	int** tab;

public:
	void wypisz_matrix();
	Matrix operator+(const Matrix& other);
	int*& operator[](const int& index) const;
	void operator=(const Matrix& other);
	Matrix operator-(const Matrix& other);

	Matrix(const int &N, const int &M);
	Matrix(const Matrix& other);
	~Matrix();

	friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
		for (int i = 0; i < m.N; ++i) {
			for (int j = 0; j < m.M; ++j) {
				os << m.tab[i][j] << "  ";
			}
			os << '\n';
		}
		return os;
	}
};

void Matrix::wypisz_matrix()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << tab[i][j] << "  ";
		}
		cout << endl;
	}
}


Matrix::Matrix(const int& wiersze, const int& kolumny)
{
	N = wiersze;
	M = kolumny;
	tab = new int* [N];
	for (int i = 0; i < N; i++){
		tab[i] = new int[M];
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << "Dodane macierze:[" << i << "]" << "[" << j << "]: " << endl;
			cin >> tab[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& other)
{
	this->M = other.M;
	this->N = other.N;	
	this->tab = new int*[other.N];
	for (int i = 0; i < other.N; i++){
		tab[i] = new int[other.M];
	}
	for (int i = 0; i < other.N; i++){
		for (int j = 0; j < other.M; j++){
			tab[i][j] = other[i][j];
		}
	}
}

int*& Matrix::operator [](const int& index) const  // overloading operator []
{
	return  tab[index];
}


void Matrix::operator=(const Matrix& other)   // overloading operator =
{
	if (tab != other.tab && M == other.M && N == other.N)
	{
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				tab[i][j] = other.tab[i][j];
			}
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < N; i++){
		delete[] tab[i];
	}
	delete[] tab;
}


Matrix Matrix::operator+(const Matrix& other)
{
	Matrix temp(*this);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			temp.tab[i][j] = this->tab[i][j] + other.tab[i][j];
		}
	}
	return temp;
}

Matrix Matrix::operator-(const Matrix& other)
{
	Matrix temp(*this);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			temp.tab[i][j] = this->tab[i][j] - other.tab[i][j];
		}
	}
	return temp;
}

int main()
{
	setlocale(LC_ALL, " ");
	
	Matrix tab1(3, 2);
	Matrix tab2(3, 2);
	
	cout << tab1 << endl;
	cout << tab2 << endl;

	cout << "tab0 = tab1 + tab2: " << endl;
	Matrix tab0 = tab1 + tab2;
	cout << tab0 << endl;

	cout << "tab0 = tab2 - tab1: " << endl;
	tab0 = tab2 - tab1;
	cout << tab0 << endl;
	return 0;
}
