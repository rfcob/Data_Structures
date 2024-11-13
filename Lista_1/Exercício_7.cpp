#include <iostream>
using namespace std;

//________________________________________________________________________________________
//Funação imprime


int imprime(int conjunto[], int tamanho, string nome){
    
    cout << endl << "\n";
    cout << " A " << nome << " dos conjuntos é" << endl << "\n";
    
    //imprime o primeiro conjunto
    for (int i = 0; i < tamanho; i++) {
        cout <<  conjunto[i] << " ";
    }

    cout << endl << '\n';

    return 0;
}


//______________________________________________________________________________________
//Funcão Intersecção - A intersecacao dos conjuntos a o agrupamento de todos os elementos diferentes


int inteseccao(int conjunto1[], int conjunto2[], int tamanho1, int tamanho2){

    string nome;
    int tamanho=0, valor=0;

    for(int i=0; i < tamanho1; i++){
        for (int j=0; j< tamanho2; j++){
            if (conjunto1[i]==conjunto2[j]){
                //valor=conjunto1[i];
                tamanho+=1;
                break;
            }
        }
    }

    int interseccao[tamanho];
    int cont=0;
    for(int i=0; i < tamanho1; i++){
        for (int j=0; j< tamanho2; j++){
            if (conjunto1[i]==conjunto2[j]){
                interseccao[cont++]=conjunto1[i];
                break;
            }
        }
            
    }

    return imprime(interseccao,tamanho,nome="inteseccao");

    

    return 0;
}
//____________________________________________________________________________________
//Função diferença

int diferenca(int conjunto1[], int conjunto2[], int tamanho1, int tamanho2){

    string nome;
    int tamanho, tam_conj_1=0,tam_conj_2=0;

    for(int i=0; i < tamanho1; i++){
        bool cond=true;
        for (int j=0; j< tamanho2; j++){
            if (conjunto1[i]==conjunto2[j]){
                cond=false;
                break;
            }
        }
        if(cond==true){
            tam_conj_1+=1;
        }
    }

    for(int i=0; i < tamanho2; i++){
        bool cond=true;
        for (int j=0; j< tamanho1; j++){
            if (conjunto2[i]==conjunto1[j]){
                cond=false;
                break;
            }
        }
        if(cond==true){
            tam_conj_2+=1;
        }
    }

    tamanho=tam_conj_1+tam_conj_2;

    //cout<<" Tamanho " << tamanho<< " " ; 

    int diferenca[tamanho];
    int cont=0;

    for(int i=0; i < tamanho1; i++){
        bool cond=true;
        for (int j=0; j< tamanho2; j++){
            if (conjunto1[i]==conjunto2[j]){
                cond=false;
                break;
            }
        }                
        if(cond==true){
            diferenca[cont++]=conjunto1[i];
        }
    }

    for(int i=0; i < tamanho2; i++){
        bool cond=true;
        for (int j=0; j< tamanho1; j++){
            if (conjunto2[i]==conjunto1[j]){
                cond=false;
                break;
            }
        }                
        if(cond==true){
            diferenca[cont++]=conjunto2[i];
        }
    }


    return imprime(diferenca,tamanho,nome="Diferença");

    return 0;

}

//___________________________________________________________________________________
//Função uniao - a junção de todos os elementos do conjunto mas sem repetir.

int uniao(int conjunto1[], int conjunto2[], int tamanho1, int tamanho2){

    string nome;
    int repetidos=0, tamanho;

    for(int i=0; i < tamanho1; i++){
        for (int j=0; j< tamanho2; j++){
            if (conjunto1[i]==conjunto2[j]){
                repetidos+=1;
            }
        }
    }

    tamanho=(tamanho1+tamanho2)-repetidos;
   
    //cout<<" Tamanho " << tamanho << " " ; 

    int uniao[tamanho];
    int indice=0;
    for(int i = 0 ; i < tamanho1; i++){
        uniao[indice++]=conjunto1[i];
        }
    
    for (int i=0;i<tamanho;i++){
        bool cond=true;
        for(int j = 0; j < tamanho2; j++){
            if(conjunto2[i]==uniao[j]){
                cond=false;
                break;                
            }
        }
        if(cond==true){
            uniao[indice++]=conjunto2[i];
        }
    }

    return imprime(uniao,tamanho,nome="União");

    return 0;
}



//____________________________________________________________________________________


int main() {
    int tam_conj_1,tam_conj_2;
    string nome;

    cout << "Entre com o tamanho do primeiro conjunto: " << "\n";
    cin >> tam_conj_1;

    cout << "Entre com o tamanho do segundo conjunto: " << "\n";
    cin >> tam_conj_2;


    int conjunto_1[tam_conj_1], conjunto_2[tam_conj_2];

    cout << "Entre com o primeiro conjunto: " << " ";
    for (int i = 0; i < tam_conj_1; i++) {
        cin >> conjunto_1[i];
    }

    cout << "Entre com o segundo conjunto: " << " ";
    for (int i = 0; i < tam_conj_2; i++) {
        cin >> conjunto_2[i];
    }

    //imprimindo primeiro conjunto
       // imprime(conjunto_1, tam_conj_1,nome="Teste");
       // imprime(conjunto_2, tam_conj_2, nome="1");


    inteseccao(conjunto_1, conjunto_2, tam_conj_1,tam_conj_2);

    diferenca(conjunto_1, conjunto_2, tam_conj_1,tam_conj_2);

    uniao(conjunto_1, conjunto_2, tam_conj_1,tam_conj_2);

    return 0;
}