#include<stdio.h>
#include<conio.h>
#include<string.h>

int push(char ch, char * stack, int top, int n) {
    if(top==n-1) {
        printf("overflow");
    } else {
        top++;
        stack[top] = ch;
    }
    return top;
}

int pop(char * stack, int top) {
    if(top==-1) {
        printf("underflow");
    } else {
        top--;
        printf("%c", stack[top+1]);
    }
    return top;
}

void main() {
    char str[50], stack[50];
    int top=-1, i;

    printf("enter string: ");
    scanf("%s", str);

    for(i=0; i<strlen(str); i++) {
        top = push(str[i], stack, top, strlen(str));
    }

    for(i=0; i<strlen(stack); i++) {
        top = pop(stack, top);
    }
}