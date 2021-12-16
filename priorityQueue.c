#include<stdio.h>
#include<conio.h>

#define N 5

struct queue
{
    int front[N];
    int rear[N];
    int q[N][N];
};

void create(struct queue *qu) {
    int i,j;
    for(i=0; i<N; i++) {
        qu->front[i] = -1;
        qu->rear[i] = -1;
        for(j=0; j<N; j++) {
            qu->q[i][j] = '\0';
        }
    }
}

void enqueue(struct queue *qu, int x, int pr) {
    pr--;

    if((qu->front[pr] == 0 && qu->rear[pr] == N-1) || (qu->front[pr]==qu->rear[pr]+1)) {
        printf("overflow\n");
        return;
    }
    if(qu->front[pr] == -1) {
        qu->front[pr] = qu->rear[pr] = 0;
    }
    else {
        if(qu->rear[pr]==N-1)
            qu->rear[pr]=0;
        else
            qu->rear[pr]++;
    }
    qu->q[pr][qu->rear[pr]] = x;
}

int dequeue(struct queue *qu) {
    for(int pr=0; pr<N; pr++) {

        if(qu->front[pr] == -1)
            continue;
        
        int x = qu->q[pr][qu->front[pr]];
        qu->q[pr][qu->front[pr]] = 0;

        if(qu->front[pr] == qu->rear[pr]) {
            qu->front[pr] = qu->rear[pr] = -1;
        }
        else {
            if(qu->front[pr] == N-1) {
                qu->front[pr] = 0;
            }
            else {
                qu->front[pr]++;
            }
        }

        return x;
    }
    printf("underflow\n");
}

void display(struct queue *qu) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d", qu->q[i][j]);
        }
        printf("\n");
    }
}

void main() {
    struct queue qu;
    create(&qu);

    int ch,x,pr;
    
    while(1) {
        printf("enter choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("enter element and priority:\n");
                scanf("%d%d",&x,&pr);
                enqueue(&qu,x,pr);
                break;
            case 2:
                dequeue(&qu);
                break;
            case 3:
                display(&qu);
                break;
            case 4:
                exit(0);
        }
    }
}