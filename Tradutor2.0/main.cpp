#include "lista.h"
#include <bits/stdc++.h>
using namespace std;

int main(){

    Dici* trad = inicializar();
    int cod, op, cont_op = 0;
    string port, ing;

    cout << "======= MENU =======" << endl;
    cout << "0 - Carregamento inicial de palavras;" << endl;
    cout << "1 - Insercao de Palavras (Portugues e Ingles);" << endl;
    cout << "2 - " << endl;
    cout << "3 - " << endl;
    cout << "4 - Exibir dicionario;" << endl;

    cout << "\n======= Inicializando Dicionario =======" << endl;
    cout << "Entre com o numero total de operacoes que deseja realizar: " << endl;
    cin >> op;

    do{

      cout << "\n======= MENU =======" << endl;
      cout << "0 - Carregamento inicial de palavras;" << endl;
      cout << "1 - Insercao de Palavras (Portugues e Ingles);" << endl;
      cout << "2 - " << endl;
      cout << "3 - " << endl;
      cout << "4 - Exibir dicionario;" << endl;

      cout << "\nEntre com o codigo da operacao que deseja realizar: " << endl;
      cin >> cod;

      switch (cod){

        case 0:
            cout << "\n======= Realizando carregamento inicial... =======" << endl;
            trad = carrega_inic(trad);
            if(trad != NULL){
                cout << "Carregamento executado com sucesso!" << endl;
            }else{
                cout << "Nao foi possivel realizar o carregamento! Tente novamente." << endl;
            }
            break;

        case 1:
            cout << "\n======= Inicializando insercao de palavras... =======" << endl;
            cout << "Insira a palavra em portugues: " << endl;
            cin >> port;
            cout << "Insira a traducao da palavra em ingles: " << endl;
            cin >> ing;
            trad = insere_ord(trad, port, ing);
            if(trad != NULL){
                cout << "Insercao feita com sucesso!" << endl;
            }
            cont_op++;
            break;

        case 4:
            cout << "\n======= Realizando impressao dos componentes presentes no dicionario =======" << endl;
            imprimir_Dici(trad);
            break;


        default:
            cout << "\nCodigo invalido! Tente novamente." << endl;

      }

    }while(cont_op != op);

    desalocaNo(trad);

    return 0;

}
