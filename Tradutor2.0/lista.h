#ifndef LISTA.H
#define LISTA.H
#include <bits/stdc++.h>
using namespace std;

typedef struct Dicionario{
    string port;
    string ing;
    struct Dicionario* prox;
}Dici;

Dici* inicializar();
Dici* carrega_inic(Dici *ptr);

Dici* alocaNo();
void desalocaNo(Dici* ptr);

Dici* insere_fim(Dici* ptr, string port, string ing);
Dici* insere_ord(Dici* ptr, string port, string ing);

Dici* remover_palavra(Dici* ptr, string palavra);

Dici* busca(Dici* ptr, string palavra);

void imprimir_Dici(Dici* ptr);




#endif
