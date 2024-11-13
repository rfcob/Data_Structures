//Questão 3.  Escreva uma função iterativa que, dada uma matriz real, calcule a matriz transposta.

#include <iostream>
using namespace std;

int main(){
    int matriz[3][3], matriz_transp[3][3], i , j;

    cout << "Entre com os valores da matriz 3x3: " << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> matriz[i][j];
        }
    }

    cout << endl;

    cout << "A matriz de entrada: " << endl <<"\n";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << matriz[i][j] <<" ";
        }
        cout <<endl;
    }
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matriz_transp[j][i]=matriz[i][j];
        }
    }
    cout <<endl;

    cout << "A matriz Trasposta: " << endl <<"\n";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << matriz_transp[i][j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;

    return 0;
}