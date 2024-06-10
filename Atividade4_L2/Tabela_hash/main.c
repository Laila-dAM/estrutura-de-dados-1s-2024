#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Inserir\n");
    printf("2. Buscar\n");
    printf("3. Remover\n");
 printf("4. Exibir Tabela\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    HashTable* ht = createTable();
    int choice, key, value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &key);
                printf("Digite o valor: ");
                scanf("%d", &value);
                insert(ht, key, value);
                break;
            case 2:
                printf("Digite a chave para buscar: ");
                scanf("%d", &key);
                value = search(ht, key);
                if (value != -1) {
                    printf("Valor encontrado: %d\n", value);
                } else {
                    printf("Chave %d não encontrada.\n", key);
                }
                break;
            case 3:
                printf("Digite a chave para remover: ");
                scanf("%d", &key);
                delete(ht, key);
                break;
            case 4:
                displayTable(ht);
                break;
            case 5:
                freeTable(ht);
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

