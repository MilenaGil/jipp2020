#include <iostream>     
#include <iomanip>      

using namespace std;

int main()
{
    double double_value = 3.14159;

    cout << setprecision(4) << double_value << endl;
    cout << setprecision(9) << double_value << endl;
    cout << fixed;
    cout << setprecision(5) << double_value << endl;
    cout << setprecision(10) << double_value << endl;;

    return 0;
}
