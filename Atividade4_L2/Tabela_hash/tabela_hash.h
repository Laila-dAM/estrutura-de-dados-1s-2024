#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;
