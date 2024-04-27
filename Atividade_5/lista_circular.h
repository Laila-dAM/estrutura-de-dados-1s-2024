#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct No {
    char valor;
    struct No* proximo;
} No;

void inserir_no(No** inicio, char valor);
void imprimir_lista(No* inicio);
void remover_no(No** inicio, char valor);
void liberar_lista(No** inicio);

#endif