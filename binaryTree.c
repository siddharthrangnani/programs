#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* lptr;
    struct Node* rptr;
};

int pre[] = {1,2,7,8,3,10,11};
int in[] = {7,2,8,1,10,3,11};

int search(int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (in[i] == value)
            return i;
    }
}

struct Node* buildTree(int start, int end) {
    static int i=0;

    if(start>end) {
        return NULL;
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = pre[i];
    node->lptr = NULL;
    node->rptr = NULL;
    i++;

    if(start==end) {
        return node;
    }

    int ind = search(start, end, node->data);

    node->lptr = buildTree(start, ind-1);
    node->rptr = buildTree(ind+1, end);

    return node;
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->lptr);
 
    printPostorder(node->rptr);
 
    printf("%d ", node->data);
}

void main() {
    struct Node* root;
    root = buildTree(0, 6);

    printPostorder(root);
}