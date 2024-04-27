#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

void inserir_no(No** inicio, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
}