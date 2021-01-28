#include <iostream>
#include <string>
#include <fstream>
#include <exception>

#include <Lab6/employee.hpp>
using namespace std;
//tworzenie pracownika
void Employee::createEmployee(string id, string name, string surname, string position) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->position = position;
}

//get
string Employee::getId() {
    return this->id;
}
string Employee::getName() {
    return this->name;
}
string Employee::getSurname() {
    return this->surname;
}
string Employee::getDepartmentId() {
    return this->departmentId;
}
string Employee::getPosition() {
    return this->position;
}

//set
void Employee::setId(string id) {
    this->id = id;
}
void Employee::setName(string name) {
    this->name = name;
}
void Employee::setSurname(string surname) {
    this->surname = surname;
}
void Employee::setDepartmentId(string departmentId) {
    this->departmentId = departmentId;
}
void Employee::setPosition(string position) {
    this->position = position;
}
