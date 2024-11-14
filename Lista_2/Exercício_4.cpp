//Questão 4.  Escreva uma função que calcule o determinante de uma matriz 3 × 3.
#include <iostream>
using namespace std;


//Imprimindo uma matriz

void imprime(int matriz[3][3]){
    cout << "A matriz que entrou é: " <<endl <<"\n";
    for(int i=0; i <3; i++){
        for(int j=0; j <3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


// Calculando o determinante
int determinante(int matriz[3][3]){
    int det;

    det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) 
        - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) 
        + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    //cout << det << endl;

   return det;
}

int main(){

    int matriz[3][3], i , j, det;

    //Criando a matriz
    cout << "Entre com os valores da matriz 3x3: " << endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> matriz[i][j];
        }
    }

    imprime(matriz);

    cout << endl;

    cout <<"O determinante da matriz é: " << (det = determinante(matriz)) << endl << "\n";

    cout << endl;

    

    return 0;
}