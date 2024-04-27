#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct No {
    char valor;
    struct No* proximo;
} No;
