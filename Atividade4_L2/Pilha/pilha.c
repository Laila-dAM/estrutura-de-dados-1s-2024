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
