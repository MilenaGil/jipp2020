#include <iostream>
using namespace std;

//program sprawdzajacy czy podane liczby to liczby skojarzone
int main()
{
    int a,b,twoja_a,twoja_b,sum=0, sum2=0;
    cout<<"Podaj liczbe twoja_a: ";
	cin>>twoja_a;
	cout<<"Podaj liczbe twoja_b: ";
	cin>>twoja_b;
	
    cout<<"Dzielniki liczby twoja_a (bez twoja_a)  to: ";
    for (int i = 1; i < twoja_a; ++i) {
        if (twoja_a % i == 0) {
            cout<<i<<", ";
            sum+=i;
        }
    }
    cout<<endl<<"Suma dzielników liczby twoja_a to: "<<sum;
    b=sum - 1;
    cout<<endl<<"b to: "<<b;
    
    cout<<endl<<"Dzielniki liczby b (bez b) to: ";
    for (int i = 1; i < b; ++i) {
        if (b % i == 0) {
            cout<<i<<", ";
            sum2+=i;
        }
    }
    cout<<endl<<"Suma dzielników liczby b to: "<<sum2<<endl;
    a=sum2 - 1;
    cout<<"a to: "<<a<<endl;
    
    if(a==twoja_a && b==twoja_b)
        cout<<"Podane liczby to liczby skojarzone."<<endl;
    else 
        cout<<"Podane liczby nie sa liczbami skojarzonymi, bo albo a!=twoje_a albo b!=twoje_b albo oba przypadki."<<endl;
    
    
    return 0;
}