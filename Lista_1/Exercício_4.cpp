#include <iostream>
using namespace std;

int main(){
    float num_1, num_2, soma, subtr, div, mult, operacao;
    bool cond;

    cout << "MENU" << endl << "\n"
         << " Entre com a operação desejada"<< endl <<"\n"
         << " 1 - Soma"<< endl 
         << " 2 - SUbtração"<< endl
         << " 3 - Multiplicação"<< endl 
         << " 4 - Divisão"<< endl
         << " 5 - Sair"<< endl <<"\n";
    cond=true;
    while(cond==true){
        cout <<" Entre com a operação desejada: "  << endl;
        cin >> operacao;
        if(operacao==5){
            cout << "Fim do Progrma";
            cond=false;
        }
        if(operacao==1){
            cout <<" Entre com os dois números"  <<  endl;
            cin >> num_1 >> num_2;
            cout << " A soma é: " << " " << (soma=num_1+num_2) << endl << "\n";
        }else if(operacao==2){
            cout <<" Entre com os dois números"  <<  endl;
            cin >> num_1 >> num_2;
            cout << " A subtração é: " << " " << (subtr=num_1-num_2) << endl << "\n";     
        }else if(operacao==3){
            cout <<" Entre com os dois números"  <<  endl;
            cin >> num_1 >> num_2;
            cout << " A multiplicação é: " << " " << (div=num_1*num_2) << endl << "\n";
        }else if (operacao==4){
            cout <<" Entre com os dois números"  <<  endl;
            cin >> num_1 >> num_2;
            cout << " A divisão é: " << " " << (num_1/num_2) << endl << "\n";
        }

    }
    return 0;
}