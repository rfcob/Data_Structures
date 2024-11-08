#include <iostream>
using namespace std;

int main(){
    int num, v_aux = 0,  num_novo = 0, saida,teste;
    bool cond;

    cout << " Entre com um número para testá-lo se é palíndromo: " << " " << endl << "\n";
    cin>>num;

    teste=num;//criado pois no teste final num foi dividido ate zero e da erro. a copia 'e para o teste
    
    cond=true;
    while (cond){
        v_aux=num%10;
        num=num/10;
        num_novo=num_novo*10+v_aux;

        if (num==0)
            cond=false;
    }

    saida=num_novo;

     if (teste==saida){
        cout << "O número é um capicua" << endl << "\n";
     }else{
        cout << "O número não é um capicua" << endl << "\n";
     }
    return 0;
}