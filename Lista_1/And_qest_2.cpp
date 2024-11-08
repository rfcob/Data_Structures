#include <iostream>
using namespace std;

int main(){
    int num, rest, div, aux = 0,  num_novo =0, saida,teste;
    bool cond;
    cin>>num;
    teste=num;//criado pois no teste final num foi dividido ate zero e da erro. a copia 'e para o teste
    cond=true;
    while (cond){
        aux=num%10;
        //cout<<aux << endl << "\n";
        num=num/10;
        //cout<<num << endl << "\n";
        num_novo=num_novo*10+aux;
        if (num==0)
            cond=false;
        //}//else{
           // cout<<"calculando" << endl << "\n";
        //}
    }

saida=num_novo;
cout << "Invertido" << " " <<  num_novo << endl;

     if (teste==saida){
        cout << "ok" << endl;
     }else{
        cout << "fodeu";
     }
return 0;
}