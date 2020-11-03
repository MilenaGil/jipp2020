#include <iostream>
using namespace std;

template <class T> void swap ( T* a, T* b )
{
  T c = a; a=b; b=c;
}

void funkcja(int &p, int &s){
        int w = p;
        p = s;
        s = w;
         cout<<"|Fun 1|"<<endl;
}

void funkcja(int *p, int *s){
        int w = *p;
        *p = *s;
        *s = w;
        cout<<"|Fun 2|"<<endl;
}

int main(){
    int a, b ,x1,x2;
    cout<<"Wprowadz liczby: "<<endl;
    cin >> a >> b;
    cout<<"Liczba a to:"<< a << ",liczba b to: "<< b<<endl;
    int *p = NULL;
    int *s = NULL;
    p = &a;
    s = &b;
    x1=a;
    x2=b;
    
    funkcja(a, b);
    std::cout<<"Po zamianie a to:"<< a << ", b to: "<< b<< endl;
    a=x1;
    b=x2;
    cout<<"Po zresetowaniu do dawnych wartosci: liczba a to:"<< a << ",liczba b to: "<< b<<endl;

    funkcja(p, s);
    std::cout<<"Po zamianie liczba a to:"<< a << ",liczba b to: "<< b<< endl;
    return 0;
}