#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* lista_criar(){
    No* cabeca = (No*)malloc(sizeof(No));
    if (cabeca != NULL){
        cabeca->proximo = NULL;
        refurn cabeca;
    }

    else {
        printf("Erro: não foi possível alocar memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
}

void lista_inserir_final(No* L, char dado) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL){
        novo->dado = dado;
        novo->proximo = NULL;
        No*atual = L;
        while (atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    else {
        printf("Erro: não foi possível alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
}

