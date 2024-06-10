#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

HashTable* createTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
