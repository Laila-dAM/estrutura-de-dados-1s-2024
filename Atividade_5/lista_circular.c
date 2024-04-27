#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

void inserir_no(No** inicio, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;

    if (*inicio == NULL){
        *inicio = novo_no;
        novo_no->proximo = novo_no;
    } 
    else {
        No* temp = *inicio;
        while(temp->proximo != *inicio){
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
        novo_no->proximo = *inicio;
    }
}

void imprimir_lista(No* inicio) {
    if(inicio == NULL) {
        printf("Lista vázia.");
        return;
    }
    No* temp = inicio;
    do {
        printf("%c ", temp->valor);
        temp = temp->proximo;
    }
    while (temp != inicio);
}