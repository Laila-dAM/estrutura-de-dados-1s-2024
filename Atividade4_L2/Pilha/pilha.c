#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->dados = (int *)malloc(capacidade * sizeof(int));
    return pilha;
}

void destruirPilha(Pilha *pilha) {
    free(pilha->dados);
    free(pilha);
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int estaCheia(Pilha *pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

void empilhar(Pilha *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("Pilha cheia! Não é possível empilhar o valor %d.\n", valor);
        return;
    }
    pilha->dados[++(pilha->topo)] = valor;
    printf("Empilhado: %d\n", valor);
}
int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    }
    return pilha->dados[(pilha->topo)--];
}

int topo(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return pilha->dados[pilha->topo];
}
