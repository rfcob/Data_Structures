#include <iostream>
using namespace std;

int main() {

    int i, lista[8], menor, maior;

    for(i=0;i<8;i++){
        cin >> lista[i];
    }

    //para imprimir
    //for(i=0;i<8;i++){
    //    cout << lista[i];
    //}
    
    menor=lista[0];
    for(i=0;i<8;i++){
        if (lista[i] < menor){
            menor=lista[i];
        }
    }
    //cout << menor << endl << "\n";

    maior=lista[0];
    for(i=0;i<8;i++){
        if (lista[i] > maior){
            maior=lista[i];
        }
    }

    //cout << maior << endl << "\n";

    cout << " A diferença absoluta entre os dois número é: " << (maior - menor) << endl << "\n";

}