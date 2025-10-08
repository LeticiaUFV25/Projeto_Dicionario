#include "lista.h"


Dici* inicializar(){
    return NULL;
}

Dici* alocaNo(){
    return new Dici;
}
void desalocaNo(Dici* ptr){
    delete ptr;
}

Dici* insere_fim(Dici* ptr, string port, string ing){
    Dici* novo = alocaNo();

    if(novo != NULL){
        novo->port = port;
        novo->ing = ing;
        novo->prox = NULL;
    }
    if(ptr == NULL){
        return novo;
    }else{
        Dici* aux = ptr;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return ptr;
}


Dici* remover_palavra(Dici* ptr, string palavra){

}

Dici* busca(Dici* ptr, string palavra){

}

void imprimir_Dici(Dici* ptr){

}
