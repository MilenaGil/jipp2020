#include <iostream>
using namespace std;

int funkcja(int &iloczyn, int &suma){
        int w = iloczyn;
        iloczyn*=suma;
        suma+=w;
        return iloczyn;
}

int main(){
    int a, b;
    cout<<"Wprowadz liczby: "<<endl;
    cin >> a >> b;
    cout<<"Liczba a to:"<< a << ",liczba b to: "<< b<<endl;
    
    
    std::cout<<"Iloczyn to:"<< funkcja(a, b) ;
    std::cout<< ", suma to: "<< b << endl;
    return 0;
    }