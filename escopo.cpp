//escopo.cpp
#include <iostream>

using std::cout;
using std::endl;

void useLocal(void);        //prototipo da função
void useStaticLocal(void);
void useGlobal(void);

int x = 1;
int y = 1;

int main(){
    int x = 5;
    int y = 9;
    cout << "Local X no escopo e: " << x << endl;

    { //novo escopo
        int x = 7;
        cout << "Local Y no escopo e: " << y << endl;
    }
}
