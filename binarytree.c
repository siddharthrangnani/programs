#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct bst{
int data;
struct bst *left;
struct bst *right;
};
//it creates new node in tree with left and right null and with given data
struct bst* newnode(int data)
{
    struct bst* bst=(struct bst*)malloc(sizeof(struct bst));
            bst->data=data;
        bst->left=NULL;
        bst->right=NULL;
        return(bst);


}

int main()
{
    struct bst* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->right->right=newnode(4);
    printf("%d",root->data);

    printf("%d",root->left->data);
    printf("%d",root->right->data);

    return 0;
}
