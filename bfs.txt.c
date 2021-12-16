#include<stdio.h>
#include<conio.h>

#define MAX 100

int queue[MAX];
int front=-1, rear=-1;

void enqueue(int elem) {
    if(front == MAX-1) {
        printf("queue overflow");
    } else {
        rear++;
        queue[rear] = elem;

        if(front==-1) {
            front++;
        }
    }
}

int dequeue() {
    if(front==-1&&rear==-1) {
        printf("queue underflow");
    } else {
        int temp = queue[front];
        queue[front]=0;
        if(front==rear) {
            front=-1;
            rear=-1;
        } else {
            front++;
        }
        return temp;
    }
}

void main() {
    int u;
    int i;
    int n;

    int matr[20][20];

    printf("enter no. of nodes:");
    scanf("%d", &n);

    printf("enter matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matr[i][j]);
        }
    }

    printf("enter starting node:");
    scanf("%d", &i);

    int visited[20];
    for(int i=0; i<20; i++) {
        visited[i] = 0;
    }

    printf("BST Traversal:\n");

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while(front!=-1 && rear!=-1) {
        int node = dequeue();

        for(int j=0; j<n; j++) {
            if(matr[node][j] == 1 && visited[j]==0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}