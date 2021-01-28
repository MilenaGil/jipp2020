#ifndef HRMS_HEADER
#define HRMS_HEADER

#include <string>
using namespace std;

class HRMS {
    private:

    public:
    void add(Employee employee, string departmentId, double salary); //metoda dodaj¹ca uzytkownika do systemu, do danego departamentu, majacego dane wynagrodzenie
    void printDepartment(string departmentId); //metoda wypisujaca wszystkich pracownikow danego departamentu
    void changeSalary(string employeeId, double salary); // metoda zmieniajaca wynagrodzenie danego pracownika
    void printSalaries(); //metoda wypisujaca wynagrodzenia wszystkich pracownikow, wraz z informacjami o tych pracownikach
    void printSalariesSorted(); //metoda wypisujaca wynagrodzenia wszystkich pracownikow, wraz z informacjami o tych pracownikach, w kolejnosci malejacego wynagrodzenia (sortowanie ma byc wykonane z uzyciem algorithm)
};

#endif
