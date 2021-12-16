#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char data[100];
    struct Node* next;
    struct Node* prev;
};

struct Node* current;

void insertAtBeginning(struct Node** head, char *new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *first = *head;

    strcpy(new_node->data,new_data);
    new_node->next = new_node;
    new_node->prev = new_node;

    if(*head == NULL) {
        *head = new_node;
        current = new_node;
        return;
    }

    new_node->next = first;
    new_node->prev = first->prev;
    
    
    first->prev = new_node;
    (new_node->prev)->next= new_node;
    
    *head = new_node;
    return;
}

void insertAtEnd(struct Node** head, char *new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *first = *head;

    strcpy(new_node->data,new_data);
    new_node->next = new_node;
    new_node->prev = new_node;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    new_node->next = first;
    new_node->prev = first->prev;

    first->prev = new_node;
    (new_node->prev)->next= new_node;
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

    if(ptr->next == ptr) {
        *head = NULL;
        free(head);
        return;
    }
    
    *head = ptr->next;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
}

void deleteFromEnd(struct Node** head) {
    struct Node* ptr;

    if(head==NULL) {
        printf("list empty");
        return;
    }

    ptr = *head;

    if(ptr->next==ptr) {
        free(head);
        *head=NULL;
        return;
    }

    ptr=ptr->prev;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;

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

void printList(struct Node *node) {
    struct Node *first = node;

    system("cls");
    printf("Playlist:\n\n");
    do {
        printf("%s\n", node->data);
        node = node->next;
    } while(node!=first);

    printf("\nNow Playing: %s", current->data);
}

void playNext() {
    if(current!=NULL) {
        current = current->next;
    }
    printf("\nNow Playing: %s", current->data);
}

void playPrevious() {
    if(current!=NULL) {
        current = current->prev;
    }
    printf("\nNow Playing: %s", current->data);
}

void playFirst(struct Node *head) {
    if(current!=NULL) {
        current = head;
    }
    printf("\nNow Playing: %s", current->data);
}

void playLast(struct Node *head) {
    if(current!=NULL) {
        current = head->prev;
    }
    printf("\nNow Playing: %s", current->data);
}

void playSpecific(struct Node *head, char *data) {
    struct Node* ptr;
    ptr = head;

    while(ptr!=NULL && strcmp(ptr->data, data)!=0) {
        ptr=ptr->next;
    }

    if(strcmp(ptr->data, data)==0) {
        current = ptr;
    }
    printf("\nNow Playing: %s", current->data);
}

void main() {
    struct Node* head = NULL;
    int ch;
    char data[100], node[100];

    while(1) {
    system("cls");

    printf("Music Playlist:\n\n1.Insert at beginning\n2.Insert at end\n3.Insert in between\n4.Delete from beginning\n5.Delete from end\n6.Delete from between\n7.Print\n");
    printf("\n8.Play next\n9.Play previous\n10.Play first\n11.Play last\n12.Play specific\n\nEnter choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("Enter music name: ");
        scanf("%s", data);
        insertAtBeginning(&head, data);
        break;

    case 2:
        printf("Enter music name: ");
        scanf("%s", data);
        insertAtEnd(&head, data);
        break;

    case 3:
        printf("Enter music name: ");
        scanf("%s", data);

        printf("Enter music name to add after: ");
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
        printf("Enter music name to delete: ");
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
        playFirst(head);
        break;

    case 11:
        playLast(head);
        break;

    case 12:
        printf("Enter music name to play: ");
        scanf("%s", node);
        playSpecific(head, node);
        break;
    
    default:
        exit(0);
        break;
    }
    getch();
    }
}