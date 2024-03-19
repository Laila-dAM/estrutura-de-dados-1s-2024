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

    
}