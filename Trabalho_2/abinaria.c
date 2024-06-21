#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

Node* searchNode(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

Node* findMinimumNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMinimumNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node *root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("In-Order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    int searchKey = 40;
    Node *searchResult = searchNode(root, searchKey);
    if (searchResult != NULL) {
        printf("Found %d in the tree.\n", searchKey);
    } else {
        printf("%d not found in the tree.\n", searchKey);
    }

    int deleteKey = 30;
    root = deleteNode(root, deleteKey);
    printf("In-Order Traversal after deletion of %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
