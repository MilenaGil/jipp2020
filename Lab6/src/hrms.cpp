#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <vector>
#include <map>
#include <algorithm>

#include <Lab6/employee.hpp>
#include <Lab6/hrms.hpp>
#include <wyjatki.hpp>
using namespace std;

vector<Employee> spisPracownikow; //kontener w ktorym beda przechowywani wszyscy pracownicy
map<string, string> idDepIdEmp; //kontener w ktorym bedzie przechowywane mapowanie pomiedzy identyfikatorami departamentow a identyfikatorami wszystkich pracownikow danego departamentu
map<string, double> employeeSalary; //kontener przechowywujacy informacje o zarobkach pracownikow

void HRMS::add(Employee employee, string departmentId, double salary) {
    employee.setDepartmentId(departmentId);
    spisPracownikow.push_back(employee);
    idDepIdEmp.insert(make_pair(departmentId, employee.getId()));
    employeeSalary.insert(make_pair(employee.getId(),salary));
}

void HRMS::printDepartment(string departmentId) {
    brak_pracownikow brak_pracownikow;
    brak_departamentow brak_departamentow;
    try {
        if(spisPracownikow.size()==0) throw brak_pracownikow;
        if(idDepIdEmp.size()==0) throw brak_departamentow;
        cout<<endl;
        for(int i=0; i<spisPracownikow.size(); i++) {
            if(spisPracownikow[i].getDepartmentId() == departmentId) {
                cout<<"ID: ";
                cout.width(4);
                cout<<left<<spisPracownikow[i].getId()<<" Name: ";
                cout.width(15);
                cout<<spisPracownikow[i].getName()<<" ";
                cout.width(15);
                cout<<spisPracownikow[i].getSurname()<<" Position: ";
                cout.width(25);
                cout<<spisPracownikow[i].getPosition()<<endl;
            }
        }
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}

void HRMS::changeSalary(string employeeId, double salary) {
    brak_ID_pracownika brak_ID_pracownika;
    try {
        if(employeeId.size()==0) throw brak_ID_pracownika;
        employeeSalary[employeeId] = salary;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}

void HRMS::printSalaries() {
    brak_pracownikow brak_pracownikow;
    try {
        if(spisPracownikow.size()==0) throw brak_pracownikow;
        map<string, double>::iterator itr; 
        cout<<endl;
        for(itr = employeeSalary.begin(); itr != employeeSalary.end(); itr++) {
            string temp = itr->first;
            Employee tempEmp;

            for(int i=0; i<spisPracownikow.size(); i++)
                if(temp == spisPracownikow[i].getId()) tempEmp = spisPracownikow[i];

            cout<<"Salary: ";
            cout.width(4);
            cout<<itr->second<<" ID: ";
            cout.width(4);
            cout<<left<<temp<<" Name: ";
            cout.width(15);
            cout<<tempEmp.getName()<<" ";
            cout.width(15);
            cout<<tempEmp.getSurname()<<" Department ID: ";
            cout.width(10);
            cout<<tempEmp.getDepartmentId()<<" Position: ";
            cout.width(25);
            cout<<tempEmp.getPosition()<<endl;
        }
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}

void HRMS::printSalariesSorted() {
    brak_pracownikow brak_pracownikow;
    try {
        if(spisPracownikow.size()==0) throw brak_pracownikow;
        map<string, double>::iterator itr; 
        typedef pair<double, string> pary;
        vector<pary> vec;

        cout<<endl;

        for(itr = employeeSalary.begin(); itr != employeeSalary.end(); itr++) {
            vec.push_back(make_pair(itr->second, itr->first));
        }

        sort(vec.begin(), vec.end());

        for(int i=0; i<vec.size();i++) {
            string temp = vec[i].second;
            Employee tempEmp;

            for(int j=0; j<spisPracownikow.size(); j++)
                if(temp == spisPracownikow[j].getId()) tempEmp = spisPracownikow[j];

            cout<<"Salary: ";
            cout.width(4);
            cout<<vec[i].first<<" ID: ";
            cout.width(4);
            cout<<left<<temp<<" Name: ";
            cout.width(15);
            cout<<tempEmp.getName()<<" ";
            cout.width(15);
            cout<<tempEmp.getSurname()<<" Department ID: ";
            cout.width(10);
            cout<<tempEmp.getDepartmentId()<<" Position: ";
            cout.width(25);
            cout<<tempEmp.getPosition()<<endl;
        }
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}
