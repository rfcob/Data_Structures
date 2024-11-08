#include<iostream>
using namespace std;

int main(){
    int n, n_novo, div, n_soma,n_quad;
    cout << "Entre com um número a ser testado: " << endl << endl;
    cin >> n;
    div = n%100;  //dividindo por 100 e quardando o resto da divisão
    n_novo = n/100; // dividindo por 100, o C irá armazenar somente a perte inteira
    cout << " O valor digitado foi: "
         << n << " " 
         << n_novo << " "
         << div <<  endl << endl;
    //criando a soma e o quadrado pra teste     
    n_soma=n_novo+div; 
    n_quad=n_soma*n_soma; 

    if (n_quad == n){
        cout << " O número ter a propriedade desejada" << endl << endl;
    } else{
        cout << "O número não tem a propriedade a ser testada " << endl << endl;
    }

    cout << n_quad;
}