#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char data[100];
    struct Node* next;
    struct Node* prev;
};

struct Node* current = NULL;

void insertAtBeginning(struct Node** head, char *new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *first = *head;

    strcpy(new_node->data,new_data);
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL) {
        *head = new_node;
        current = new_node;
        return;
    }

    new_node->next = first;
    new_node->prev = NULL;
    
    first->prev = new_node;

    *head = new_node;
    return;
}

void printList(struct Node *node) {
    struct Node* ptr;

    while(node!=NULL) {
        ptr = node;
        printf("%s ", node->data);
        node = node->next;
    }

    printf("\n");
    printf("Now Playing: %s", current->data);

    // while(ptr!=NULL) {
    //     printf("%s ", ptr->data);
    //     ptr = ptr->prev;
    // }
}

void insertAtEnd(struct Node** head, char *new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head;

    strcpy(new_node->data,new_data);
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    while(last->next!=NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
    return;
}

void insertAfter(struct Node** head, char *new_data, char *after) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *current = *head;

    strcpy(new_node->data,new_data);
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    while(strcmp(current->data, after)!=0) {
        if(current->next==NULL) {
            printf("node not found");
            return;
        }
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    new_node->prev = current;
    if(new_node->next!=NULL)
        (new_node->next)->prev = new_node;
    
    return;
}

void deleteFromBeginning(struct Node** head) {
    struct Node* ptr;

    if(head==NULL) {
        printf("list empty");
        return;
    }

    ptr = *head;

    if(ptr->next == NULL) {
        *head = NULL;
        free(head);
        return;
    }
    
    *head = ptr->next;
    (ptr->next)->prev = NULL;
    free(ptr);
}

void deleteFromEnd(struct Node** head) {
    struct Node* ptr;

    if(head==NULL) {
        printf("list empty");
        return;
    }

    ptr = *head;

    if(ptr->next==NULL) {
        free(head);
        *head=NULL;
        return;
    }

    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }

    (ptr->prev)->next=NULL;

    free(ptr);
}

void deleteFromBetween(struct Node** head, char *delData) {
    struct Node* ptr;

    if(head==NULL) {
        printf("list empty");
        return;
    }

    ptr = *head;

    while(ptr!=NULL && strcmp(ptr->data, delData)!=0) {
        ptr=ptr->next;
    }

    if(ptr==NULL) {
        printf("data not found");
    }
    else if(strcmp(ptr->data, delData)==0) {
        (ptr->prev)->next = ptr->next;
        (ptr->next)->prev = ptr->prev;
        free(ptr);
    }
}

void playNext() {
    if(current!=NULL) {
        current = current->next;
    }
    printList(head);
}

void playPrevious() {
    if(current!=NULL) {
        current = current->prev;
    }
    printList(head);
}

void playFirst() {
    if(current!=NULL) {
        current = current->next;
    }
    printList(head);
}

void main() {
    struct Node* head = NULL;
    int ch;
    char data[100], node[100];

    while(1) {
    system("cls");

    printf("Enter choice:\n1.Insert at beginning\n2.Insert at end\n3.Insert in between\n4.Delete from beginning\n5.Delete from end\n6.Delete from between\n7.Print\n");
    printf("Enter choice:\n8.Play next\n9.Play previous\n10.Play first\n11.Play last\n12.Play specific\n");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("Enter data:");
        scanf("%s", data);
        insertAtBeginning(&head, data);
        break;

    case 2:
        printf("Enter data:");
        scanf("%s", data);
        insertAtEnd(&head, data);
        break;

    case 3:
        printf("Enter data:");
        scanf("%s", data);

        printf("Enter node to insert after:");
        scanf("%s", node);

        insertAfter(&head, data, node);
        break;

    case 4:
        deleteFromBeginning(&head);
        break;

    case 5:
        deleteFromEnd(&head);
        break;

    case 6:
        printf("Enter node to delete after:");
        scanf("%s", node);
        deleteFromBetween(&head, node);
        break;

    case 7:
        printList(head);
        break;

    case 8:
        playNext();
        break;

    case 9:
        playPrevious();
        break;

    case 10:
        playFirst(&head);
        break;

    case 11:
        playLast();
        break;

    case 12:
        playSpecific();
        break;
    
    default:
        exit(0);
        break;
    }
    getch();
    }

    // insertAtBeginning(&head, "abcd");
    // insertAtBeginning(&head, 15);
    // insertAtBeginning(&head, 2);
    // insertAtBeginning(&head, 4);
    // insertAtBeginning(&head, 9);

    // insertAtEnd(&head, "zzz");
    // insertAtEnd(&head, 55);

    // insertAfter(&head, 76, 2);
    // insertAfter(&head, 43, 9);

    // deleteFromBeginning(&head);
    // deleteFromBeginning(&head);

    // deleteFromEnd(&head);
    // deleteFromEnd(&head);

    // deleteFromBetween(&head, 2);
    // deleteFromBetween(&head, 76);

    // printList(head);
}