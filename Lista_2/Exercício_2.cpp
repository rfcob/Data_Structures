//Questão 2.  Escreva uma função iterativa para decidir se uma matriz é simétrica.

#include <iostream>
using namespace std;


//função para verificar simétria:

bool eh_simetrica(int matriz[3][3]){

    for(int i=0; i <3; i++){
        for(int j=0; j <3; j++){
            if(matriz[i][j]!=matriz[j][i]){
                return false;
            }
        }
    }
    return true;
}

//função para imprimir matriz


int main(){

    /*int linhas, colunas;

    cout << "Entre com o numero de Linhas da Matriz: ";
    cin >> linhas;
    cout << "Entre com o numero de Colunas da Matriz: ";
    cin >> colunas;

    int matriz_simetrica[linhas][colunas], resposta;
    */

   int matriz_simetrica[3][3], resposta;

    cout << "Entre com os valores da matriz:" ;
    for(int i=0; i <3; i++){
        for(int j=0; j <3; j++){
            cin >> matriz_simetrica[i][j];
        }
    }    

    /*
    cout << "A matriz que entrou é: " <<endl <<"\n";
    for(int i=0; i <3; i++){
        for(int j=0; j <3; j++){
            cout << matriz_simetrica[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << endl << "\n";    

    resposta=eh_simetrica(matriz_simetrica);

    if(resposta){
        cout<<"É simétrica" << endl << "\n";
    }else{
        cout<<"Não é simétrica" << endl << "\n";
    }

    return 0;
}