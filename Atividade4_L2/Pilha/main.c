#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1. Empilhar\n");
    printf("2. Desempilhar\n");
    printf("3. Exibir Topo\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int capacidade;
    printf("Digite a capacidade da pilha: ");
    scanf("%d", &capacidade);

    Pilha *pilha = criarPilha(capacidade);
    int opcao, valor;
