#include <iostream>
using namespace std;

void funkcja(int &p, int &s){
        int w = p;
        p = s;
        s = w;
}

int main(){
    int a, b ;
    cout<<"Wprowadz liczby: "<<endl;
    cin >> a >> b;
    cout<<"Liczba 1 wynosi:"<< a << ",liczba 2 wynosi: "<< b<<endl;
    
    
    funkcja(a, b);
    std::cout<<"Po zamianie liczba 1 wynosi:"<< a << ",liczba 2 wynosi: "<< b<< endl;
    return 0;
    }