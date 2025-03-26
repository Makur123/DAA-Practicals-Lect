#include<stdio.h>
struct node {
    int data;
    node* next;
    char color;
};

struct node *newNode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


int main()