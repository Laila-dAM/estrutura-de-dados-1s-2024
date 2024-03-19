#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Quantos números você deseja inserir? ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Número inválido. Encerrando o programa.\n");
        return 1;
    }

    int *numbers = malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }
    
    printf("Insira os %d números separados por espaços:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    qsort(numbers, n, sizeof(int), compare);
    
    int sum = 0;
    int min = numbers[0];
    int max = numbers[n - 1];
    
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    
    float average = (float)sum / n;
    
    printf("Quantidade de números inseridos: %d\n", n);
    printf("Valor médio dos números: %.1f\n", average);
    printf("Menor número: %d\n", min);
    printf("Maior número: %d\n", max);
    printf("Números em ordem crescente: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    
    printf("\n");
    
    free(numbers);
    
    return 0;
}
