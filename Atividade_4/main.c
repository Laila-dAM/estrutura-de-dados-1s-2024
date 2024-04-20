#include <stdio.h>
#include "lista.h"

int main() {
    No* lista = lista_criar();

    lista_inserir_final(lista, 'A');
    lista_inserir_final(lista, 'B');
    lista_inserir_final(lista, 'C');
    lista_inserir_final(lista, 'D');
    lista_inserir_final(lista, 'E');

printf("Lista original: ");
    lista_imprimir(lista);
    
    char valor_busca = 'C';
    printf("Verificar existência de '%c': %d\n", valor_busca, lista_verificar_existencia(lista, valor_busca));
    
    printf("Ocorrências de '%c': %d\n", valor_busca, lista_verificar_ocorrencias(lista, valor_busca));
    
    printf("Lista inversa: ");
    lista_imprimir_inversa(lista->proximo);
    printf("NULL\n");
    
    int i = 2;
    printf("Inserir '%c' na posição %d: ", 'X', i);
    lista_inserir_no_i(lista, i, 'X');
    lista_imprimir(lista);
    
    i = 4;
    printf("Remover nó na posição %d: ", i);
    lista_remover_no_i(lista, i);
    lista_imprimir(lista);
    
    valor_busca = 'B';
    printf("Remover nós com o valor '%c': ", valor_busca);
    lista_remover_no(lista, valor_busca);
    lista_imprimir(lista);
    
    lista_destruir(lista);
    
    return 0;
}


}