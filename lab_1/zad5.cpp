#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
    int i, j,TAB[2][3],tab1[2][3],tab2[2][3]; 
    
    cout<<"Elementy tab1: "<<endl;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            cout<<"Podaj tab1["<<i<<"]["<<j<<"]= ";
            cin>>tab1[i][j];
        }
        cout<<endl;
    }
    
    cout<<"Elementy tab2: "<<endl;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            cout<<"Podaj tab2["<<i<<"]["<<j<<"]= ";
            cin>>tab2[i][j];
        }
        cout<<endl;
    }
    
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)
            TAB[i][j]=tab1[i][j]+tab2[i][j];
    }
    
    cout<<"Tablica (macierz), ktora jest suma tab1 i tab2: "<<endl;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            cout << setw(10);
            cout<<TAB[i][j];
        }
        cout<<endl;
    }
    return 0;
}
