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

    while (1) {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para empilhar: ");
                scanf("%d", &valor);
                empilhar(pilha, valor);
                break;
            case 2:
                valor = desempilhar(pilha);
                if (valor != -1) {
                    printf("Desempilhado: %d\n", valor);
                }
                break;
            case 3:
                valor = topo(pilha);
                if (valor != -1) {
                    printf("Topo: %d\n", valor);
                }
                break;
            case 4:
                destruirPilha(pilha);
                printf("Programa encerrado.\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
