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

void printList(struct Node *node) {
    while(node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void main() {
    int n,data;
    struct Node* head = NULL;

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;
    struct Node* head4 = NULL;

    printf("Enter total number:");
    scanf("%d",&n);

    printf("Enter numbers:\n");

    for(int i=0; i<n; i++) {
        scanf("%d",&data);
        insertAtEnd(&head, data);
    }
    
    struct Node* nxt = head;

    for(int i=1; i<=n; i++) {
        int d = nxt->data;
        if(d%4==1)
            insertAtEnd(&head1, nxt->data);

        else if(d%4==2)
            insertAtEnd(&head2, nxt->data);

        else if(d%4==3)
            insertAtEnd(&head3, nxt->data);

        else if(d%4==0)
            insertAtEnd(&head4, nxt->data);

        nxt=nxt->next;
    }

    printf("\nA: ");
    printList(head1);
    printf("\nB: ");
    printList(head2);
    printf("\nC: ");
    printList(head3);
    printf("\nD: ");
    printList(head4);
}