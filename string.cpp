//String.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <locale.h>

using namespace std;

int main(){

    string nome1, nome2, nome3;
    cout << "Informe nome 1: ";
    fflush(stdin);
    getline(cin,nome1);
    //cin >> nome1;

    cout << "Informe nome 2: ";
    fflush(stdin);
    cin >> nome2;

    cout << "Informe nome 3: ";
    fflush(stdin);
    cin >> nome3;


    cout << "\nNome 1: " << nome1 << endl;
    cout << "\nNome 2: " << nome2 << endl;
    cout << "\nNome 3: " << nome3 << endl;
}
