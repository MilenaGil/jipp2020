#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int w=argc - 1;
    int tab2[w],tab[w]; //tab[]={100, 2, 30, 5, 8, 34, 56, 78, 90};
    for (int i = 0; i < w; i++)
    {
        tab[i] = atoi(argv[i+1]);
    }

    //for(int i=0;i<w;i++)
    //    cout<< tab[i] << ", " ;

    int x,i;
    for (int a=1;a<((w/2)+ 1);a++){
        tab2[0]=tab[0];
        for(i=1;i<w;i++){
            if(tab[i]<tab2[i - 1]){
                tab2[i]=tab2[i - 1];
                tab2[i - 1]=tab[i];
            }else{
                tab2[i]=tab[i];
            }
        }
        tab[0]=tab2[0];
        for(i=1;i<w;i++){
            if(tab2[i]<tab[i - 1]){
                tab[i]=tab[i - 1];
                tab[i - 1]=tab2[i];
            }else{
                tab[i]=tab2[i];
            }
        }
    }
    
    for(i=0;i<w;i++)
        cout<< tab[i] << ", " ;
       
    return 0;
}