#include "lista.h"


Dici* inicializar(){
    return NULL;
}

Dici* carrega_inic(Dici* ptr){
    ptr = insere_ord(ptr, "Oi", "Hi");
    ptr = insere_ord(ptr, "Bom", "Good");
    ptr = insere_ord(ptr, "Obrigado", "Thanks");
    ptr = insere_ord(ptr, "Eu", "Me");
    ptr = insere_ord(ptr, "Dia", "Day");
    return ptr;
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

Dici* insere_ord(Dici* ptr, string port, string ing){

    Dici* novo = alocaNo();

    if(novo != NULL){
        novo->port = port;
        novo->ing = ing;
        novo->prox = NULL;
    }
    if(ptr == NULL){
        return novo;
    }else if(novo->port < ptr->port){
        novo->prox = ptr;
        return novo;
    }else{
        Dici* ant = ptr;
        Dici* seg = ptr->prox;
        while(seg != NULL && seg->port < novo->port){
            ant = seg;
            seg = seg->prox;
        }
        ant->prox = novo;
        novo->prox = seg;
    }
    return ptr;

}

Dici* remover_palavra(Dici* ptr, string palavra){

}

Dici* busca(Dici* ptr, string palavra){

}

void imprimir_Dici(Dici* ptr){

    Dici *aux = ptr;

    while(aux != NULL){
        cout << aux->port << " - " << aux->ing << endl;
        aux = aux->prox;
    }

}

