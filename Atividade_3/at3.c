#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    if(argc !=2){
        printf("Uso: %s arquivo\n", argv[0]);
        return 1;
    }

    FILE *arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    int quantidade_numeros = 0;
    int numero;
    while (fscanf(arquivo_entrada, "%d", &numero) == 1){
        quantidade_numeros++;
    }

    fseek(arquivo_entrada, 0, SEEK_SET);

    int *numeros = (int *)malloc(quantidade_numeros *sizeof(int));
    if (numeros == NULL){
        printf("Error ao alocar memória\n");
        fclose(arquivo_entrada);
        return 1;
    }

    for (int i = 0; i < quantidade_numeros; i++){
        fscanf(arquivo_entrada, "%d", &numeros[i]);
    }
    fclose(arquivo_entrada);

    qsort(numeros, quantidade_numeros, sizeof(int), compara);

    FILE *arquivo_saida = fopen("saida.txt", "w");
if (arquivo_saida == NULL){
    printf("Erro ao abrir o arquivo de saída\n");
    free(numeros);
    return 1;
}

for (int i=0; i < quantidade_numeros; i++){
    fprintf(arquivo_saida, "%d\n", numeros[i]);
}

fclose(arquivo_saida);
free(numeros);
printf("Arquivo de saida 'saida.txt' gerado com sucesso :D\n");
return 0;
}