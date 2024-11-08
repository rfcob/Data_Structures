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

    getline(cin, cadastro.nome);
    cin >> cadastro.idade;
    std::cin.ignore();
    getline(cin, cadastro.endereco);
    cout << cadastro.nome << " mora no endereço: " << cadastro.endereco << " e tem " << cadastro.idade  << " de idade. " << endl <<"\n";

return 0;
}