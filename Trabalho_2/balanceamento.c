#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* rotateRight(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

struct TreeNode* rotateLeft(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

int balanceFactor(struct TreeNode* node);  // Declaração da função balanceFactor

struct TreeNode* insertNode(struct TreeNode* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;

    int balance = balanceFactor(node);

    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int balanceFactor(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("Árvore balanceada em ordem: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
