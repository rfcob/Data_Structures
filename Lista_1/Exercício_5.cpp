#include <iostream>
using namespace std;

int main(){
    int numero;

    cout << "Entre com um número inteiro" << endl;
    cin >> numero;

    if (numero%5==0 && numero %3==0){
        cout << " O Número é divisível por 3 e por 5" << endl << "\n";
    }else{
        cout << " O  número não é divisível por ambos, 3 e 5" << endl << "\n";
    }
    return 0;
}