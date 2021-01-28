#include <exception>
using namespace std;

class brak_pracownikow : public exception
{
    virtual const char *what() const throw()
    {
        return "Brak pracownikow";
    }
};

class brak_ID_pracownika : public exception
{
    virtual const char *what() const throw()
    {
        return "Brak ID pracownika";
    }
};

class brak_departamentow : public exception
{
    virtual const char *what() const throw()
    {
        return "Brak departamentow";
    }
};
