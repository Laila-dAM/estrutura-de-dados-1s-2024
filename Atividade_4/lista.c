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

void lista_imprimir_inversa(No* L) {
    if (L->proximo != NULL) {
        lista_imprimir_inversa(L->proximo);
        printf("%c ->", L->dado);
    }
}

void lista_inserir_no_i(No* L, int i, char dado) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL){
        novo->dado = dado;
        No* atual = L;
        for (int j = 0; j < i && atual->proximo !=NULL; j++){
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    else {
        printf("Erro: não foi possível alocar memória para o novo nó,\n");
        exit(EXIT_FAILURE);
    }
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;

    for (int j=0; j < i && atual->proximo !=NULL; j++){
        atual = atual->proximo;

    }

    if (atual->proximo != NULL){
        No* temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL){
        if (atual->proximo->dado == valor_busca){
            No* temp = atual->proximo;
            atual->proximo = temp->proximo;
            free(temp);
        }

        else {
            atual = atual->proximo;
        }
    }
}

void lista_destruir(No* L){
    No* atual = L->proximo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(L);
}