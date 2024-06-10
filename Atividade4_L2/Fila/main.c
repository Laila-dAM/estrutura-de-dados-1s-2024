#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Enfileirar\n");
    printf("2. Desenfileirar\n");
    printf("3. Exibir Fila\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}
int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite um valor para enfileirar: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Desenfileirado: %d\n", value);
                }
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                freeQueue(q);
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}


