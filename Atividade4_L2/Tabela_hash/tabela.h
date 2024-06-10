#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

HashTable* createTable();
void insert(HashTable* ht, int key, int value);
int search(HashTable* ht, int key);
void delete(HashTable* ht, int key);
void displayTable(HashTable* ht);
void freeTable(HashTable* ht);
#endif
