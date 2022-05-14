//escopo-unario.cpp
#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>

using std::setprecision;

//Definição da global PI
const double PI = 3.14159265359;

int main()
{
    //definição da constante local PI
    const float PI = static_cast < float > (::PI);

    //imprima os valores da global e local de PI
    cout << setprecision (20)
         << "Local float do valor de PI = " << PI
         << "\nGlobal double do Valor de PI =  " << ::PI << endl;

    return 0;
}
