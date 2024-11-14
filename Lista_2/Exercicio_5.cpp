//Questão 5.  Escreva uma função que calcule o produto de duas matrizes.

#include <iostream>
using namespace std;


//função para imprimir
void imprime(int matriz[3][3]){
    //cout << "A matriz que entrou é: " <<endl <<"\n";
    for(int i=0; i <3; i++){
        for(int j=0; j <3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//função para multiplicar
int multiplica_matriz(int matriz1[3][3], int matriz2[3][3] ){
    int matriz3[3][3]={0};

    for(int i=0; i <3; i++){
        for(int j=0; j <3; j++){
            for(int k=0; k<3; k++){
                matriz3[i][j]+=matriz1[i][k]*matriz2[k][j];
            }
        }
    }

    imprime(matriz3);

    return 0;
}


int main(){

    int matriz_1[3][3],matriz_2[3][3],cond=0, i, j, det;

    //Criando as matrizes
    while(cond<2){
    cout << "Entre com os valores da matriz 3x3: " << endl;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(cond==0){
                cin >> matriz_1[i][j];
                }if(cond==1){
                    cin >> matriz_2[i][j];
                }
            }
        }
        cond++;
    }

    //imprime(matriz_1);
    //cout << endl;
    //imprime(matriz_2);

    cout << " A matriz produto é: " << (multiplica_matriz(matriz_1,matriz_2)) << endl << "n";

    return 0;

}
