#include "lista.h"
#include <bits/stdc++.h>
using namespace std;

int main(){

    Dici* trad = inicializar();
    int cod, op, cont_op = 0;
    bool remov;
    string port, ing, bu;

    cout << "======= MENU =======" << endl;
    cout << "0 - Carregamento inicial de palavras;" << endl;
    cout << "1 - Insercao de Palavras (Portugues e Ingles);" << endl;
    cout << "2 - Remocao de Palavras" << endl;
    cout << "3 - Busca de Palavras;" << endl;
    cout << "4 - Exibir dicionario;" << endl;
    cout << "5 - Traducao de Texto (Insira um texto em e obtenha sua traducao);" << endl;

    cout << "\n======= Inicializando Dicionario =======" << endl;
    cout << "Entre com o numero total de operacoes que deseja realizar: " << endl;
    cin >> op;

    do{

      cout << "\n======= MENU =======" << endl;
      cout << "0 - Carregamento inicial de palavras;" << endl;
      cout << "1 - Insercao de Palavras (Portugues e Ingles);" << endl;
      cout << "2 - Remocao de Palavras;" << endl;
      cout << "3 - Busca de Palavras ;" << endl;
      cout << "4 - Exibir Dicionario;" << endl;
      cout << "5 - Traducao de Texto (Insira um texto e obtenha sua traducao);" << endl;

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
            cont_op++;
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

        case 2:
            cout << "\n======= Inicializando remocao pela palavra em portugues =======" << endl;
            cout << "Entre com a palavra em portugues: " << endl;
            cin >> port;
            remov = remover_palavra(&trad, port);
            if(remov == true){
                cout << "Remocao feita com sucesso!" << endl;
            }else{
                cout << "Nao foi possivel realizar a remocao! Tente novamente" << endl;
            }
            cont_op++;
            break;

        case 3:
            cout << "\n======= Inicializando Busca de Palavras =======" << endl;
            cout << "Entre com uma palavra para obter sua respectiva traducao" << endl;
            cin >> port;
            bu = busca(&trad, port);
            if(bu == "0"){
                cout << "O dicionario nao possui a traducao para a palavra buscada! Insira a palavra e sua traducao em nosso sitema e tente novamente." << endl;
            }else {
                cout << "A traducao para a palavra " << port << " eh: " << bu << "." << endl;
            }
            cont_op++;
            break;

        case 4:
            cout << "\n======= Realizando impressao dos componentes presentes no dicionario =======" << endl;
            imprimir_Dici(trad);
            cont_op++;
            break;

        case 5:

            cout << "\n======= Inicializando Traducao =======" << endl;
            traducao(&trad);
            cont_op++;
            break;

        default:
            cout << "\nCodigo invalido! Tente novamente." << endl;

      }

    }while(cont_op != op);

    desalocaNo(trad);

    return 0;

}
