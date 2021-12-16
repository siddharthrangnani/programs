#include<stdio.h>
#include<conio.h>

#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

void enqueue(int elem) {
    if((front==0 && rear == MAX-1) || (front == rear+1)) {
        printf("queue overflow");
    } else {
        rear = (rear+1)%MAX;
        queue[rear] = elem;

        if(front==-1) {
            front++;
        }
    }
}

void dequeue() {
    if(front==-1&&rear==-1) {
        printf("queue underflow");
    } else {
        queue[front]=0;
        if(front==rear) {
            front=-1;
            rear=-1;
        } else {
            front = (front+1)%MAX;
        }
    }
}

void display() {
    printf("\n");
    for(int i=0; i<MAX; i++) {
        printf("%d ", queue[i]);
    }
}

void main() {
    int ch;
    int elem;
    while(1) {
        printf("Choose operation:\n1.Insert\n2.Delele\n3.Display\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element:");
                scanf("%d", &elem);

                enqueue(elem);
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            default:
                exit(0);
        }
    }
    
}