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

void lista_imprimir(No* L){
    No* atual = L->proximo;
    while (atual != NULL){
        printf("%c ->", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int lista_verificar_existencia(No* L, char valor_busca){
    No* atual = L->proximo;

    while (atual != NULL){
        if (atual->dado == valor_busca){
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_verifica_ocorrencias(No* L, char valor_busca){
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL){
        if (atual->dado == valor_busca) {
            ocorrencias++;
        }

        atual = atual->proximo;
    }
    return ocorrencias;
}

