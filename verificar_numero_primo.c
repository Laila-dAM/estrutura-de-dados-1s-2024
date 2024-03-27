#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificarPrimo(int numero) {
    if (numero <= 1) return false; // 0 e 1 não são primos

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false; // se o número é divisível por i, não é primo
    }

    return true; // se nenhum divisor foi encontrado, é primo
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);

    if (numero == 0 && argv[1][0] != '0') {
        printf("Por favor, insira um número inteiro válido como argumento.\n");
        return 1;
    }

    if (verificarPrimo(numero)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
