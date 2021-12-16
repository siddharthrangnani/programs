#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char name[100];
    long key;
    struct Node* lptr;
    struct Node* rptr;
};

struct Node* newNode(int key, char* name)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    strcpy(temp->name, name);
    temp->lptr = temp->rptr = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key, char* name) {
    if(node == NULL) {
        return newNode(key, name);
    }

    if(strcmp(name, node->name) < 0) {
        node->lptr = insert(node->lptr, key, name);
    } else {
        node->rptr = insert(node->rptr, key, name);
    }

    return node;
}

struct Node* minNode(struct Node* node) {
    struct Node* curr = node;

    while(curr && curr->lptr != NULL) {
        curr = curr->lptr;
    }

    return curr;
}

struct Node* delete(struct Node* root, char* name) {
    if(root == NULL) {
        return root;
    }

    if(strcmp(name, root->name) < 0) {
        root->lptr = delete(root->lptr, name);
    }

    else if(strcmp(name, root->name) > 0) {
        root->rptr = delete(root->rptr, name);
    }

    else {
        if(root->lptr == NULL) {
            struct Node* temp = root->rptr;
            free(root);
            return temp;
        }

        else if(root->rptr == NULL) {
            struct Node* temp = root->lptr;
            free(root);
            return temp;
        }

        struct Node* temp = minNode(root->rptr);
        root->key = temp->key;
        strcpy(root->name, temp->name);
        root->rptr = delete(root->rptr, temp->name);
    }

    return root;
}

void printAscending(struct Node* root)
{
    if (root != NULL) {
        printAscending(root->lptr);
        printf("%s: ", root->name);
        printf("%d\n", root->key);
        printAscending(root->rptr);
    }
}

void printDescending(struct Node* root)
{
    if (root != NULL) {
        printDescending(root->rptr);
        printf("%s: ", root->name);
        printf("%d\n", root->key);
        printDescending(root->lptr);
    }
}

void search(struct Node* root, char* name) {
    if(root == NULL) {
        printf("\nentry not found");
        return;
    }

    if(strcmp(name, root->name) < 0) {
        search(root->lptr, name);
    }

    else if(strcmp(name, root->name) > 0) {
        search(root->rptr, name);
    }

    else if(strcmp(name, root->name) == 0) {
        printf("contact no.: %ld", root->key);
    }
}

void main() {
    struct Node* root = NULL;

    int ch;
    char name[100];
    long contact;

    while(1) {
        system("cls");

        printf("Enter choice:\n1. Insert record\n2. Delete record\n3. Search record\n4. Print in ascending\n5. Print in descending\n");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone no.: ");
                scanf("%ld", &contact);
                root = insert(root, contact, name);
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                root = delete(root, name);
                break;

            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                search(root, name);
                getch();
                break;

            case 4:
                printAscending(root);
                getch();
                break;

            case 5:
                printDescending(root);
                getch();
                break;
        }
    }
}