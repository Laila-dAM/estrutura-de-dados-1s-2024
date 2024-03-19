#include <stdio.h>
#include <stdlid.h>
#include <locale.h>

int c(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}