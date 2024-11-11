#include <iostream>
#include <string.h>
#include <cstdio> //para usar o scanf e o printf do C

using namespace std;

typedef struct dados{
    string nome, endereco;
    int idade;
} Dados;

int main() {

    Dados cadastro;

    cout << "Nome: ";
    getline(cin, cadastro.nome);
    cout << "Idade: ";
    cin >> cadastro.idade;
    std::cin.ignore();
    cout << "Endereço: ";
    getline(cin, cadastro.endereco);
    cout << cadastro.nome << " mora no endereço: " << cadastro.endereco <<"." << " Idade: " << cadastro.idade  << " anos. " << endl <<"\n";

return 0;
}