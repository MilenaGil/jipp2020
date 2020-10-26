#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int tab2[9],tab[]={100, 2, 30, 5, 8, 34, 56, 78, 90};
    int x,i;
    for (int a=1;a<5;a++){
        tab2[0]=tab[0];
        for(i=1;i<9;i++){
            if(tab[i]<tab2[i - 1]){
                tab2[i]=tab2[i - 1];
                tab2[i - 1]=tab[i];
            }else{
                tab2[i]=tab[i];
            }
        }
        tab[0]=tab2[0];
        for(i=1;i<9;i++){
            if(tab2[i]<tab[i - 1]){
                tab[i]=tab[i - 1];
                tab[i - 1]=tab2[i];
            }else{
                tab[i]=tab2[i];
            }
        }
    }
    
    for(i=0;i<9;i++)
        cout<< tab[i] << ", " ;
       
    return 0;
}