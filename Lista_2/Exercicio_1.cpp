#include <iostream>
#include <string.h>
#include <cstdio> //para usar o scanf e o printf do C

using namespace std;

typedef struct dados{
    string nome, endereco;
    int idade;
};

int main() {
    
    dados Dados;
    
    getline(cin, Dados.nome);
    cin >> Dados.idade;
    std::cin.ignore();
    getline(cin, Dados.endereco);
    cout << Dados.nome << " mora no endereço: " << Dados.endereco << " e tem " << Dados.idade  << " de idade. " << endl <<"\n";

}