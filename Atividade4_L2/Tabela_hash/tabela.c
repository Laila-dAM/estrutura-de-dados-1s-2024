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
   node = node->next;
    }
    return -1; // Indica que a chave não foi encontrada
}

void delete(HashTable* ht, int key) {
    int hashIndex = hashFunction(key);
    Node* node = ht->table[hashIndex];
    Node* prev = NULL;
    while (node != NULL && node->key != key) {
        prev = node;
        node = node->next;
    }
    if (node == NULL) {
        printf("Chave %d não encontrada.\n", key);
        return;
    }
    if (prev == NULL) {
        ht->table[hashIndex] = node->next;
    } else {
        prev->next = node->next;
    }
    free(node);
    printf("Chave %d removida.\n", key);
}

void displayTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Índice %d: ", i);
        Node* node = ht->table[i];
        while (node != NULL) {
            printf("-> [Chave: %d, Valor: %d] ", node->key, node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

void freeTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* node = ht->table[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(ht);
}

