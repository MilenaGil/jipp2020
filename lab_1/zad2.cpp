#include <iostream>
#include <cstring>
using namespace std;

bool fun(char tab[]);

int main(int argc, char *argv[])
{
    char tab[20];
	cout<<"Podaj wyraz: ";
	cin>>tab;
	
	if(fun(tab)==true) 
		cout<<tab<<" to palindrom"<<endl;
	else
		cout<<tab<<" nie jest palindromem"<<endl;
		
    return 0;
}

bool fun(char tab[])
{
	int a=0, x = strlen(tab) - 1;
	
	while(a<x) 
	{
		if(tab[a]!=tab[x])
		    return false;
		
		++a; 
		--x; 
	}
	return true;
}