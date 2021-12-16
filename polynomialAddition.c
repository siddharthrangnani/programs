#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int coeff, int pow) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head;

    new_node->coeff = coeff;
    new_node->pow = pow;
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

struct Node* addPolynomials(struct Node* polynomial1, struct Node* polynomial2, struct Node* polyAdd) {
    struct Node *head;

    struct Node *poly1 = polynomial1;
    struct Node *poly2 = polynomial2;

    while (poly1!=NULL && poly2!=NULL)
    {
        if(polyAdd == NULL) {
            polyAdd = (struct Node*) malloc(sizeof(struct Node));
            head = polyAdd;
        }
        else {
            head->next = (struct Node*) malloc(sizeof(struct Node));
            head = head->next;
        }
        
        if(poly1->pow > poly2->pow) {
            head->pow = poly1->pow;
            head->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        else if(poly1->pow < poly2->pow) {
            head->pow = poly2->pow;
            head->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        else {
            head->pow = poly1->pow;
            head->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1!=NULL) {
        head->next = (struct Node*) malloc(sizeof(struct Node));
        head = head->next;

        head->pow = poly1->pow;
        head->coeff = poly1->coeff;
        poly1 = poly1->next;
    }

    while (poly2!=NULL) {
        head->next = (struct Node*) malloc(sizeof(struct Node));
        head = head->next;

        head->pow = poly2->pow;
        head->coeff = poly2->coeff;
        poly2 = poly2->next;
    }
    head->next = NULL;
    return polyAdd;
}

void print(struct Node* node)
{
    while (node->next != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
}

void printList(struct Node *node) {
    while(node!=NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if(node!=NULL) {
            printf(" + ");
        }
    }
}

void main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *polyAdd = NULL;

    insertAtEnd(&poly1, 4,5);
    insertAtEnd(&poly1, 6,3);
    insertAtEnd(&poly1, 4,2);
    insertAtEnd(&poly1, 7,1);

    insertAtEnd(&poly2, 8,5);
    insertAtEnd(&poly2, 9,4);
    insertAtEnd(&poly2, 12,2);
    insertAtEnd(&poly2, 2,1);

    polyAdd = addPolynomials(poly1, poly2, polyAdd);

    printList(poly1);
    printf("\n");
    printList(poly2);
    printf("\n");
    printList(polyAdd);
}