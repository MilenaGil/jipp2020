#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
    private:
        int N, M; // N to liczba wierszy, a M to kolumn
        double *tab;

    public:
        Matrix(std::string path);
        Matrix(int n, int m);
        Matrix(int n);
        void set(int n, int m, double val);
        double get(int n, int m);
        Matrix add(Matrix m2);
        Matrix subtract(Matrix m2);
        double mnozenie_m_n(int n, int m, Matrix m2);
        Matrix multiply(Matrix m2);
        int cols();
        int rows();
        void print();
        bool store(std::string filename, std::string path);
};

Matrix::Matrix(std::string path)
{
    ifstream zrodlo;
    zrodlo.open(path);

    zrodlo >> N >> M;
    tab = new double[N*M*sizeof(double)];
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            zrodlo>>tab[i*M+j];
        }
    }
}

Matrix::Matrix(int n, int m)
{
    tab = new double[n*m*sizeof(double)];
    N = n;
    M = m;
    for (int i=0;i<N*M;i++){
        tab[i]=0.0;
        //Traktujemy tablice jednowymiarowa jako tablice dwuwymiarowa,
        //gdy ciag elementow tablicy jednowymiarowej dzielimy o liczbe kolumn tablicy dwuwymiarowej
    }
}


Matrix::Matrix(int n)
{
    tab = new double[n*n*sizeof(double)];
    N = n;
    M = n;
    for (int i=0;i<N*M;i++){
        tab[i]=0.0;
        //Traktujemy tablice jednowymiarowa jako tablice dwuwymiarowa,
        //gdy ciag elementow tablicy jednowymiarowej dzielimy o liczbe kolumn tablicy dwuwymiarowej
    }
}

void Matrix::set(int n, int m, double val){
    tab[n*M+m]=val;
}

double Matrix::get(int n, int m){
    return tab[n*M+m];
}

Matrix Matrix::add(Matrix m2){
    Matrix wynik(N,M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
           wynik.set(i,j,(get(i, j)+m2.get(i, j)));
        }
    }
    return wynik;
}

Matrix Matrix::subtract(Matrix m2){
    Matrix wynik(N,M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
           wynik.set(i,j,(get(i, j)-m2.get(i, j)));
        }
    }
    return wynik;
}

double Matrix::mnozenie_m_n(int n, int m, Matrix m2)
{
    double w = 0;
    for (int i=0; i<M; i++)
        w+= get(n, i)*m2.get(i, m);
    return w;
}

Matrix Matrix::multiply(Matrix m2)
{
    Matrix wynik(m2.cols(), N);
    int j=0;
    for (int i=0; i<wynik.rows(); i++)
        for ( j = 0; j<wynik.cols(); j++)
            wynik.set(i, j, mnozenie_m_n(i, j, m2));
    return wynik;
}

int Matrix::cols(){
    return M;
}

int Matrix::rows(){
    return N;
}

void Matrix::print(){
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cout<<get(i, j) <<"  ";
        }
    cout << endl;
    }
}

bool Matrix::store(std::string filename, std::string path){ //path = .  filename = macierz1
    ofstream wynik (path+"/"+filename);
    wynik << rows() << " " << cols() << endl;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            wynik<<get(i, j) <<"  ";
        }
    wynik << endl;
    }
    return true;
}
