#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    if(argc !=2){
        printf("Uso: %s arquivo\n", argv[0]);
        return 1;
    }

    FILE *arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }
}