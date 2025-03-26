#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;  // Assign the key value correctly
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int key) {
    if (node == NULL) return newNode(key);
    else if (key == node->key) return node;
    else if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);  // Added space for better formatting
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->key);  // Added space for better formatting
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);  // Added space for better formatting
    }
}

int main() {
    struct node *root = newNode(50);  // Create the root with the key 50
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 400);
    root = insert(root, 700);
    root = insert(root, 600);
    root = insert(root, 800);

    printf("\nThe preorder traversal: ");
    preorder(root);

    printf("\nThe Inorder traversal: ");
    inorder(root);

    printf("\nThe postorder traversal: ");
    postorder(root);

    return 0;
}
