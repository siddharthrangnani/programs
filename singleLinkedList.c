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
        return;
    }

    new_node->next = *head;
    *head = new_node;
    return;
}

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

void insertAfter(struct Node** head, int new_data, int after) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *current = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    while(current->data!=after) {
        if(current->next==NULL) {
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
    struct Node* ptr;

    if(head==NULL) {
        printf("list empty");
        return;
    }

    ptr = *head;
    *head = ptr->next;
    free(ptr);
}

void deleteFromEnd(struct Node** head) {
    struct Node* last;
    struct Node* prev;

    if(head==NULL) {
        printf("list empty");
        return;
    }

    last = *head;

    if(last->next==NULL) {
        free(head);
        *head=NULL;
        return;
    }

    while(last->next!=NULL) {
        prev=last;
        last=last->next;
    }

    prev->next=NULL;
    free(last);
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
    while(node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 9);

    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 2);

    insertAfter(&head, 7, 12);
    insertAfter(&head, 3, 6);

    deleteFromBeginning(&head);
    // deleteFromBeginning(&head);

    // deleteFromEnd(&head);
    deleteFromEnd(&head);

    deleteFromBetween(&head, 5);

    printList(head);
}