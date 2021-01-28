#include <stdlib.h>
#include <iostream>
#include <time.h>

#include <Lab6/employee.hpp>
#include <Lab6/hrms.hpp>
using namespace std;

int main() {
    Employee pracownik1,pracownik2,pracownik3,pracownik4,pracownik5,pracownik6,pracownik7,pracownik8,pracownik9,pracownik10;
    HRMS H;

    pracownik1.createEmployee("1","Kazimierz","Terr","programista Back-end");
    pracownik2.createEmployee("2","Anna", "Laskowska","programista Front-end");
    pracownik3.createEmployee("3","Maria","Stuart","leader");
    pracownik4.createEmployee("4","Alex","Fuego","programista Front-end");
    pracownik5.createEmployee("5","Gosia","Arkada","leader");
    pracownik6.createEmployee("6","Daniel","Smith","leader");
    pracownik7.createEmployee("7","Wladyslaw","Nowak","programista Front-end");
    pracownik8.createEmployee("8","Karol","Kowalski","programista Back-end");
    pracownik9.createEmployee("9","Tomek","Marny","programista Back-end");
    pracownik10.createEmployee("10","Wojtek","Nietoperz","leader");

    //dane o zatrudnieniu pracownikow w departamentach
    H.add(pracownik1, "team1", 5100);
    H.add(pracownik2, "team1", 4900);
    H.add(pracownik3, "team2", 6500);
    H.add(pracownik4, "team3", 5700);
    H.add(pracownik5, "team1", 9500);
    H.add(pracownik6, "team3", 9300);
    H.add(pracownik7, "team2", 5500);
    H.add(pracownik8, "team2", 5300);
    H.add(pracownik9, "team1", 6300);
    H.add(pracownik10, "team3", 6200);
    
    //wypisanie z team1
    cout<<endl<<"Pracownicy pracujacy w departamencie team1:";
    H.printDepartment("team1");
    cout<<endl;

    //wypisanie z team2
    cout<<"Pracownicy pracujacy w departamencie team2:";
    H.printDepartment("team2");
    cout<<endl;

    //wypisanie z team3
    cout<<"Pracownicy pracujacy w departamencie team3:";
    H.printDepartment("team3");
    cout<<endl;

    //wypisanie zarobkow
    cout<<"Zarobki wszystkich pracownikow:";
    H.printSalaries();
    cout<<endl;

    //zmiana zarobkow dla Marii Stuart
    H.changeSalary("3",7200);
    
    //wypisanie zarobkow po zmianie i posortowanie
    cout<<"Posortowane zarobki pracownikow:";
    H.printSalariesSorted();
    cout<<endl;

    return 0;
}
