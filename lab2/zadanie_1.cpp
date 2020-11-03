#include <iostream>
using namespace std;

void funkcja(int *p, int *s){
    if(*p>*s){
        int w = *p;
        *p = *s;
        *s = w;
    }
}

int main(){
    int a, b;
    cout<<"Wprowadz liczby: "<<endl;
    cin >> a >> b;
    cout<<"Liczba 1 wynosi:"<< a << ",liczba 2 wynosi: "<< b<<endl;
    int *p = NULL;
    int *s = NULL;
    p = &a;
    s = &b;
    
    funkcja(p, s);
    std::cout<<"Po zamianie-do ktorej doszlo jesli pierwsza liczba jest wieksza od drugiej-Liczba 1 wynosi:"<< a << ",liczba 2 wynosi: "<< b<< endl;
    return 0;
    }