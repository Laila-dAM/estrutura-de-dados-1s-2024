#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    FILE *arq_txt;

    arq_txt = fopen("arq.txt", "w");

if(arq_txt == NULL){
    printf("Error ao abrir o arquivo arq.txt");
    exit(1);
}
    fprintf(arq.txt, "Ola arquivo.txt");
    fclose(arq.txt);

    exit(0);
}