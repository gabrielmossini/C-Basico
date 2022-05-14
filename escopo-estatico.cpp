//escopo-estatico.cpp
#include <iostream>

using namespace std;
void escopo( int curr ) {
   static int EscopoEstatico;

   EscopoEstatico += curr;
   cout << "Escopo Estatico e " << EscopoEstatico << endl;
}

int main() {
   for ( int i = 0; i < 10; i++ )
      escopo( i );
}
