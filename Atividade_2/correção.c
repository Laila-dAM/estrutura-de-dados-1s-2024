#include <stdio.h>
#include <locale.h>

int main(){
    int num, i, primo = 1;
setlocale(LC_ALL, "portuguese");
    printf("Digite um número positivo:");
    scanf("%d", &num);

    if (num <= 1){
        printf("%d não é um número primo\n, num");
        return 0;
    }

    for (i = 2; i<= num / 2; i++){
        if (num % i == 0) {
            primo = 0;
            break;
        }
    }

    if(primo == 1)
    printf("%d é um número primo.\n", num);
    else

    printf("%d não é um número primo\n", num);

    return 0;
}