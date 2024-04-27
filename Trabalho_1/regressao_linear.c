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
    int i = 0;
    while (fscanf(arquivo, "%d, %f", &pontos[i].x, &ponto[i].y) == 2){
        i++;
    }
    fclose(arquivos);

    float media_x = 0, media_y = 0;
    for (i = 0; i < num_pontos; i++) {
        media_x += pontos[i].x;
        media_y += pontos[i].y;
    }
    media_x /= num_pontos;
    media_y /= num_pontos;
    float soma_numerador = 0, soma_denominador = 0;
    for (i = 0; i < num_pontos; i++) {
        soma_numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        soma_denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x); 
    }
}