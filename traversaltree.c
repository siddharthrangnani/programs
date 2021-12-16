#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct bin{
int data;
struct bin *left;
struct bin * right;
};
void inorder(struct bin* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d",root->data);
     inorder(root->right);
}
void preorder(struct bin* root)
{
    if(root==NULL)
        return;
    printf("%d",root->data);
     preorder(root->left);

     preorder(root->right);
}
void postorder(struct bin* root)

    {
        if(root==NULL)
            return;
        postorder(root->left);
         postorder(root->right);
        printf("%d",root->data);

    }
struct bin* createnode(value)
{
    struct bin* node = (struct bin*)malloc(sizeof(struct bin));
    node->data=value;
    node->left=NULL;
    node->right=NULL;
    return node;
};
struct bin *insertleft(struct bin * head,int value)
{
    head->left=createnode(value);
    return head->left;

};
struct bin *insertright(struct bin* head,int value)
{
    head->right=createnode(value);
    return head->right;
};
int main()
{
    struct bin* root=createnode(33);
    insertleft(root,2);
    insertright(root,2);

    printf("Answer");
    inorder(root);
    preorder(root);
    postorder(root);

}
