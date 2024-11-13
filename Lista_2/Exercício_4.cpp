//Questão 4.  Escreva uma função que calcule o determinante de uma matriz 3 × 3.
#include <iostream>
using namespace std;

int main(){

    int matriz[3][3], matriz_transp[3][3], i , j;

    //Criando a matriz
    cout << "Entre com os valores da matriz 3x3: " << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> matriz[i][j];
        }
    }

    cout << endl;

    

    return 0;
}