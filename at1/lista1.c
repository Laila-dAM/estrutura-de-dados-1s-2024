#include <stdio.h>
#include <stdlid.h>
#include <locale.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int N;
    printf("=== Insira os números ===\n");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Error: Insira números!\n");
        return 0;
    }

    int numbers[N];
    printf("Insira os números inteiros:");
    for (int i = 0; i < N; i++){
        scanf("%d", &numbers[i];)
    }

    qsort(numbers, N, sizeof(int), compare);

    int sum = 0;
    int smallest = numbers[0];
    int largest = numbers[N - 1];

    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }

    printf("Quantidade de números: %d\n", N);
    printf("Média dos números: %.2f\n", (float)sum/N);
    printf("Menor número: %d\n", smallest);
    printf("Maior númeor: %d\n", largest);
    printf("Números em ordem crescente:");
    for (int i = 0; i < N; i++){
        printf("%d", numbers[i]);
    }
    printf("\n");
return 0;
}