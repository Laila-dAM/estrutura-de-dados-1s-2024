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
    
    return ht;
}

void insert(HashTable* ht, int key, int value) {
    int hashIndex = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[hashIndex];
    ht->table[hashIndex] = newNode;
}

int search(HashTable* ht, int key) {
    int hashIndex = hashFunction(key);
    Node* node = ht->table[hashIndex];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }

