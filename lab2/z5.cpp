#include <iostream>
using namespace std;

void funkcja(int *x, int *y){
        int w=*x;
        *x=*y;
        *y=w;
}
int main(){
    int a , b;
    cout<<"Wprowadz dwie liczby a, b:"<<endl;
    cin >> a >> b;
    cout<<"Adres liczby a to "<<&a<<" ,wartosc liczby a to "<<a<<endl;
    cout<<"Adres liczby b to "<<&b<<" ,wartosc liczby b to "<<b<<endl;
    funkcja(&a,&b);
    cout<<"Po zamianie: adres liczby a to "<<&a<<" ,wartosc liczby a to "<<a<<endl;
    cout<<"Po zamianie: adres liczby b to "<<&b<<" ,wartosc liczby b to "<<b<<endl;
    return 0;
    }