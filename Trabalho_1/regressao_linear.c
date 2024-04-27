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
}