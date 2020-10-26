#include <iostream>
using namespace std;

float BMI;
void fun(float &BMI,float wzrost,float masa_ciala);

int main(int argc, char *argv[])
{
    float masa_ciala=0.0 , wzrost=0.0;
    BMI=0.0;
	cout<<"Podaj swoja mase ciala w kilogramach: ";
	cin>>masa_ciala;
	cout<<"Podaj swoj wzrost w metrach: ";
	cin>>wzrost;
	
	fun(BMI, wzrost, masa_ciala);
	cout<<"Twoje BMI to: "<<BMI<<endl;
	
	if(BMI<16) 
		cout<<"To wyglodzenie !"<<endl;
	else if(BMI>=16 && BMI<17) 
		cout<<"To wychudzenie."<<endl;
	else if(BMI>=17 && BMI<18.5) 
		cout<<"To niedowaga."<<endl;
	else if(BMI>=18.5 && BMI<25) 
		cout<<"Masz prawidlowa wage. Brawo."<<endl;
	else if(BMI>=25 && BMI<30) 
		cout<<"To nadwaga."<<endl;
	else if(BMI>=30 && BMI<35) 
		cout<<"To otylosc stopnia I."<<endl;
	else if(BMI>=35 && BMI<40) 
		cout<<"To otylosc stopnia II."<<endl;
	else
		cout<<"To skrajna otylosc!"<<endl;
		
    return 0;
}

void fun(float &BMI,float wzrost,float masa_ciala)
{
	BMI=(masa_ciala)/(wzrost * wzrost);
}