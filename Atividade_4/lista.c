#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* lista_criar(){
    No* cabeca = (No*)malloc(sizeof(No));
    if (cabeca != NULL){
        cabeca->proximo = NULL;
        refurn cabeca;
    }

    else {
        printf("Erro: não foi possível alocar memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
}

