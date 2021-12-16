#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int top=-1, n = 50;
char stack[50];

int getpre(char ch) {
    int pre;

    switch (ch)
    {
        case '+':
        case '-':
            pre=1;
            break;

        case '*':
        case '/':
            pre=2;
            break;

        case '^':
            pre=3;
            break;

        default:
            break;
    }

    return pre;
}

bool isOperand(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void push(char ch) {
    if(top==n-1) {
        printf("overflow");
    } else {
        top++;
        stack[top] = ch;
    }
}

char pop() {
    if(top==-1) {
        printf("underflow");
    } else {
        top--;
        return stack[top+1];
    }
}

char* toPostfix(char * infix) {
    int i=0, j=0;
    char next;
    char *polish = malloc (sizeof (char) * 50);

    next = infix[i];

    while(next!='\0')
    {

        next = infix[i];

        if(isOperand(next)) {
            while(getpre(stack[top])>=getpre(next) && top!=-1) {
                polish[j] = pop(); 
                j++;
            }
            push(next);
        } else {
            polish[j] = next;
            j++;
        }

        i++;
        next=infix[i];
        
    }

    int t = top;

    while(t>=0) {
        polish[j] = pop();
        j++;
        t--;
    }

    return polish;
}



void main() {
    
    int i, pre;
    char infix[50];

    printf("enter string: ");
    scanf("%s", infix);

    printf("%s", toPostfix(infix));
}