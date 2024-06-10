#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha* criarPilha(int capacidade);
void destruirPilha(Pilha *pilha);
int estaVazia(Pilha *pilha);
int estaCheia(Pilha *pilha);
void empilhar(Pilha *pilha, int valor);
int desempilhar(Pilha *pilha);
int topo(Pilha *pilha);

#endif