#include <iostream>
using namespace std;

int main(){
    int x, y, aux;
    x=10;
    y=5;

    //x,y=y,x;
    //x=y;
    //y=x;

    aux=x;
    x=y;
    y=aux;


    cout << x << "\t" << y <<endl << "\n";

    cout <<" Para trocar uma variável pela outra em c++ é preciso uma variável auxiliar, o que é" << endl
         << "difente do python. Isso ocorre porque a váriavel armazenada na mémoria  e ao tentar" << endl 
         << "trocar o valor é apagado e substituido pelo novo" << endl << "\n";

}