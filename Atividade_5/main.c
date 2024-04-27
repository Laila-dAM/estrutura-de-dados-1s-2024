#include <stdio.h>
#include "lista_circular.h"

int main(){
    No* inicio = NULL;

inserir_no(&inicio, 'A');
    inserir_no(&inicio, 'B');
    inserir_no(&inicio, 'C');
    inserir_no(&inicio, 'D');

    printf("Lista circular: ");
    imprimir_lista(inicio);
    printf("\n");

    remover_no(&inicio, 'B');

    printf("Lista após remover 'B': ");
    imprimir_lista(inicio);
    printf("\n");

    liberar_lista(&inicio);

    return 0;
}
