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

int main()
{

    Matrix tab1(5, 6);
    Matrix tab2(5, 6);
    Matrix tab3(6, 5);
    Matrix tab4(5);

    //tworzenie elementow macierzy i przyklad dla set
    
    //tab1 5x6:
    tab1.set(0, 0, 3); tab1.set(0, 1, 5); tab1.set(0, 2, 5); tab1.set(0, 3, 2); tab1.set(0, 4, 9); tab1.set(0, 5, 5);
    tab1.set(1, 0, 9); tab1.set(1, 1, 1); tab1.set(1, 2, 4); tab1.set(1, 3, 3); tab1.set(1, 4, 3); tab1.set(1, 5, 7);
    tab1.set(2, 0, 7); tab1.set(2, 1, 7); tab1.set(2, 2, 8); tab1.set(2, 3, 3); tab1.set(2, 4, 9); tab1.set(2, 5, 8);
    tab1.set(3, 0, 6); tab1.set(3, 1, 1); tab1.set(3, 2, 8); tab1.set(3, 3, 5); tab1.set(3, 4, 1); tab1.set(3, 5, 3);
    tab1.set(4, 0, 2); tab1.set(4, 1, 1); tab1.set(4, 2, 9); tab1.set(4, 3, 6); tab1.set(4, 4, 1); tab1.set(4, 5, 2);

    //tab2 5x6:
    tab2.set(0, 0, 2); tab2.set(0, 1, 5); tab2.set(0, 2, 1); tab2.set(0, 3, 7); tab2.set(0, 4, 3); tab2.set(0, 5, 6);
    tab2.set(1, 0, 3); tab2.set(1, 1, 6); tab2.set(1, 2, 8); tab2.set(1, 3, 1); tab2.set(1, 4, 1); tab2.set(1, 5, 6);
    tab2.set(2, 0, 4); tab2.set(2, 1, 9); tab2.set(2, 2, 1); tab2.set(2, 3, 1); tab2.set(2, 4, 2); tab2.set(2, 5, 7);
    tab2.set(3, 0, 4); tab2.set(3, 1, 7); tab2.set(3, 2, 7); tab2.set(3, 3, 2); tab2.set(3, 4, 3); tab2.set(3, 5, 1);
    tab2.set(4, 0, 1); tab2.set(4, 1, 9); tab2.set(4, 2, 1); tab2.set(4, 3, 8); tab2.set(4, 4, 5); tab2.set(4, 5, 2);

    //tab3 6x5:
    tab3.set(0, 0, 5); tab3.set(0, 1, 9); tab3.set(0, 2, 2); tab3.set(0, 3, 1); tab3.set(0, 4, 1);
    tab3.set(1, 0, 8); tab3.set(1, 1, 5); tab3.set(1, 2, 3); tab3.set(1, 3, 1); tab3.set(1, 4, 8);
    tab3.set(2, 0, 7); tab3.set(2, 1, 5); tab3.set(2, 2, 2); tab3.set(2, 3, 6); tab3.set(2, 4, 8);
    tab3.set(3, 0, 1); tab3.set(3, 1, 1); tab3.set(3, 2, 4); tab3.set(3, 3, 6); tab3.set(3, 4, 8);
    tab3.set(4, 0, 1); tab3.set(4, 1, 1); tab3.set(4, 2, 4); tab3.set(4, 3, 1); tab3.set(4, 4, 7);
    tab3.set(5, 0, 8); tab3.set(5, 1, 2); tab3.set(5, 2, 5); tab3.set(5, 3, 2); tab3.set(5, 4, 5);

    //tab4 5x5:
    tab4.set(0, 0, 4); tab4.set(0, 1, 2); tab4.set(0, 2, 1); tab4.set(0, 3, 3); tab4.set(0, 4, 7);
    tab4.set(1, 0, 5); tab4.set(1, 1, 1); tab4.set(1, 2, 7); tab4.set(1, 3, 2); tab4.set(1, 4, 1);
    tab4.set(2, 0, 6); tab4.set(2, 1, 2); tab4.set(2, 2, 4); tab4.set(2, 3, 4); tab4.set(2, 4, 2);
    tab4.set(3, 0, 6); tab4.set(3, 1, 4); tab4.set(3, 2, 1); tab4.set(3, 3, 7); tab4.set(3, 4, 8);
    tab4.set(4, 0, 8); tab4.set(4, 1, 3); tab4.set(4, 2, 1); tab4.set(4, 3, 7); tab4.set(4, 4, 3);

    cout<<"Tab1 to:"<<endl;   //tablica 5 na 6
    tab1.print();
    cout<<"Tab2 to:"<<endl;   //potrzebne np. do dodawania i odejmowania
    tab2.print();
    cout<<"Tab3 to:"<<endl;   //potrzebne np. do mnozenia
    tab3.print();
    cout<<"Tab4 to:"<<endl;   //ta kwadratowa tablica
    tab4.print();
    
    //przyklad dla get
    cout<<"przyklad dla get-wypisanie elemetu tab1[3][4]"<<endl;
    cout<<tab1.get(3,4)<<endl;

    //przyklad z dodawaniem tab1 i tab2:
    cout<<"Dodawanie tab1 do tab2:"<<endl;
    tab1.add(tab2).print();

    //przyklad z odejmowaniem tab2 od tab1:(tab1-tab2)
    cout<<"Odejmowanie tab2 od tab1:"<<endl;
    tab1.subtract(tab2).print();

    //przyklad z mnozeniem tab1 z tab3:
    cout<<"Mnozenie tab1 z tab3:"<<endl;
    tab1.multiply(tab3).print();
    
    //przyklad dla cols
    cout<<"przyklad dla cols-wypisanie liczby kolumn tab1"<<endl;
    cout<<tab1.cols()<<endl;

    //przyklad dla rows
    cout<<"przyklad dla rows-wypisanie liczby wiersszy tab1"<<endl;
    cout<<tab1.rows()<<endl;

    //zapisywanie tab1 do pliku
    tab1.store("wynik", ".");

    //wczytywanie zapisanego pliku do nowej macierzy tab5
    cout<<"Nowa macierz tab5 na podstawie zapisanego pliku:"<<endl;
    Matrix tab5("./wynik");
    tab5.print();
}
