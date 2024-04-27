#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

int main(int argc, char *argc[]){
    if (argc != 2){
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }
    FILE *arquivo = fopen(argv[1], "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int num_pontos = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        num_pontos++;
    }
    rewind(arquivo);
    Ponto *pontos = malloc(num_pontos *sizeof(Ponto));
    if (pontos == NULL){
        printf("Erro de alocação de memória.\n");
        return 1;
    }
}