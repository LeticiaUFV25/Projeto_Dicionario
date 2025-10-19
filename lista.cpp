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
    ptr = insere_ord(ptr, "Sim", "Yes");
    ptr = insere_ord(ptr, "Nao", "No");
    ptr = insere_ord(ptr, "Para", "To");
    ptr = insere_ord(ptr, "Dentro", "In");
    ptr = insere_ord(ptr, "Eh", "Is");
    ptr = insere_ord(ptr, "Voce", "You");
    ptr = insere_ord(ptr, "Aquele", "That");
    ptr = insere_ord(ptr, "Menino", "Boy");
    ptr = insere_ord(ptr, "Menina", "Girl");
    ptr = insere_ord(ptr, "Falso", "Fake");
    ptr = insere_ord(ptr, "Verdadeiro", "True");
    ptr = insere_ord(ptr, "Pessoas", "People");
    ptr = insere_ord(ptr, "Agua", "Water");
    ptr = insere_ord(ptr, "Isso", "That");
    ptr = insere_ord(ptr, "Oque", "What");
    ptr = insere_ord(ptr, "Quer", "Want");
    ptr = insere_ord(ptr, "Bonito", "Pretty");
    ptr = insere_ord(ptr, "De", "Of");
    ptr = insere_ord(ptr, "E", "And");
    ptr = insere_ord(ptr, "Um", "A");
    ptr = insere_ord(ptr, "Uma", "A");
    ptr = insere_ord(ptr, "Este", "It");

    ptr = insere_ord(ptr, "oi", "hi");
    ptr = insere_ord(ptr, "bom", "good");
    ptr = insere_ord(ptr, "obrigado", "thanks");
    ptr = insere_ord(ptr, "eu", "me");
    ptr = insere_ord(ptr, "dia", "day");
    ptr = insere_ord(ptr, "sim", "yes");
    ptr = insere_ord(ptr, "nao", "no");
    ptr = insere_ord(ptr, "para", "to");
    ptr = insere_ord(ptr, "dentro", "in");
    ptr = insere_ord(ptr, "eh", "is");
    ptr = insere_ord(ptr, "voce", "you");
    ptr = insere_ord(ptr, "aquele", "that");
    ptr = insere_ord(ptr, "menino", "boy");
    ptr = insere_ord(ptr, "menina", "girl");
    ptr = insere_ord(ptr, "falso", "fake");
    ptr = insere_ord(ptr, "verdadeiro", "true");
    ptr = insere_ord(ptr, "pessoas", "people");
    ptr = insere_ord(ptr, "agua", "water");
    ptr = insere_ord(ptr, "isso", "that");
    ptr = insere_ord(ptr, "oque", "what");
    ptr = insere_ord(ptr, "quer", "want");
    ptr = insere_ord(ptr, "bonito", "pretty");
    ptr = insere_ord(ptr, "de", "of");
    ptr = insere_ord(ptr, "e", "and");
    ptr = insere_ord(ptr, "um", "a");
    ptr = insere_ord(ptr, "uma", "a");
    ptr = insere_ord(ptr, "este", "it");
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

    Dici* aux = ptr;
    while (aux != NULL) {
        if (aux->port == port || aux->ing == ing) {
            cout << "A palavra '" << port << "' e/ou '" << ing << "' ja existe no dicionario!" << endl;
            return ptr;
        }
        aux = aux->prox;
    }

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

bool remover_palavra(Dici** ptr, string palavra){

    Dici* aux = *ptr;
    Dici* ant = NULL;

    if(*ptr != NULL){
        while(aux != NULL && aux->port != palavra){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            *ptr = aux->prox;
            desalocaNo(aux);
        }
        if(aux != NULL){
            ant->prox = aux->prox;
            desalocaNo(aux);
        }
        return true;
    }
    return false;

}

string busca(Dici** ptr, string palavra){

    Dici *aux = *ptr;

    if(*ptr != NULL){
        while(aux != NULL){
            if(aux->port == palavra){
                return aux->ing;
            }else if(aux->ing == palavra){
                return aux->port;
            }
            aux = aux->prox;
        }
    }
    return "0";
}

void traducao(Dici** ptr){

    if (ptr == NULL || *ptr == NULL) {
        cout << "Dicionario vazio.\n";
        return;
    }

    cout << "Entre com o texto que sera traduzido:\n";
    cout << "Obs: digite '*' para parar a leitura do texto." << endl;

    string palavra;
    int cont_unk = 0;

    while (cin >> palavra) {
        if (palavra == "*"){
            break;
        }

        string temp = busca(ptr, palavra); // usa a lista encadeada como antes

        if (temp != "0") {
            cout << temp << " ";
        } else {
            cout << palavra << " ";
            ++cont_unk;
        }
    }

    cout << "\n";
    if (cont_unk != 0) {
        cout << "O texto inserido possui palavras que nao estao presentes em nosso sistema! "
             << "Se for do seu interesse complemente o dicionario com as palavras faltantes." << endl;
    } else {
        cout << "Traducao concluida sem palavras desconhecidas." << endl;
    }

}

void imprimir_Dici(Dici* ptr){

    Dici *aux = ptr;

    if(ptr == NULL){
        cout << "O dicionario se encontra vazio." << endl;
    }

    while(aux != NULL){
        cout << aux->port << " - " << aux->ing << endl;
        aux = aux->prox;
    }

}

