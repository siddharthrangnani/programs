#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        new_node->next = *head;
        return;
    }

    struct Node *last = *head;
    do {
        last = last->next;
    }while(last->next!=*head);

    new_node->next = *head;
    *head = new_node;
    last->next = *head;
    return;
}

void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        new_node->next = *head;
        return;
    }

    do {
        last = last->next;
    } while(last->next!=*head);

    last->next = new_node;
    new_node->next = *head;
    return;
}

void insertAfter(struct Node** head, int new_data, int after) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *current = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        new_node->next = *head;
        return;
    }

    while(current->data!=after) {
        if(current->next==*head) {
            printf("node not found");
            return;
        }
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    return;
}

void deleteFromBeginning(struct Node** head) {
    struct Node* ptr = *head, *first = *head;

    if(*head==NULL) {
        printf("list empty");
        return;
    }

    if(ptr->next==ptr) {
        free(head);
        *head = NULL;
        return;
    }

    while(ptr->next!=*head) {
        ptr = ptr->next;
    }

    ptr->next = first->next;

    *head = ptr->next;
    free(first);
    return;
}

void deleteFromEnd(struct Node** head) {
    struct Node *ptr = *head;
    struct Node *prev = *head;

    if(*head == NULL) {
        printf("list is empty");
        return;
    }

    if(ptr->next == ptr) {
        free(head);
        *head = NULL;
        return;
    }

    while(ptr->next != *head) {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = ptr->next;
    *head = prev->next;
    free(ptr);
}

void deleteFromBetween(struct Node** head, int delData) {
    struct Node* ptr;
    struct Node* prev;

    if(head==NULL) {
        printf("list empty");
        return;
    }

    ptr = *head;

    while(ptr!=NULL && ptr->data!=delData) {
        prev=ptr;
        ptr=ptr->next;
    }

    if(ptr==NULL) {
        printf("data not found");
    }
    else if(ptr->data==delData) {
        prev->next = ptr->next;
        free(ptr);
    }
}

void printList(struct Node *node) {
    for(int i=0; i<20; i++) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 10);

    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);

    insertAfter(&head, 3, 2);
    insertAfter(&head, 6, 9);

    deleteFromBeginning(&head);

    deleteFromEnd(&head);

    deleteFromBetween(&head, 7);

    printList(head);
}