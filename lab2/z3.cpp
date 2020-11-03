#include <iostream>
using namespace std;

void funkcja(int &a, int *b){
        int w = a;
        a = *b;
        *b = w;
}

int main(){
    int x, y ;
    cout<<"Wprowadz liczby: "<<endl;
    cin >> x >> y;
    cout<<"Liczba 1 wynosi:"<< x << ",liczba 2 wynosi: "<< y <<endl;
    int *b = NULL;
    b = &y;
    
    funkcja(x , b);
    std::cout<<"Po zamianie liczba 1 wynosi:"<< x << ",liczba 2 wynosi: "<< y << endl;
    return 0;
    }