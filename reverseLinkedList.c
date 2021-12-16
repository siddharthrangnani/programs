#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    while(last->next!=NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while(current!=NULL) {
        next = current->next;

        current->next = prev;

        prev = current;

        current = next;
    }
    *head = prev;
}

void printList(struct Node *node) {
    while(node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void main() {
    struct Node *head = NULL;

    insertAtEnd(&head, 4);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 2);

    printList(head);
    printf("\n");

    reverse(&head);

    printList(head);
}