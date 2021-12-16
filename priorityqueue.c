#include<stdio.h>
#include<conio.h>
#define max 20
int front=-1,rear=-1,pr[n],qu[n];
void enqueue(int prior,int data)
{
    if(rear=max-1)
    {
        printf("queue overflow");
    }
    else if(front==-1 && rear==-1)
    {

        front=0;
        rear=0;
        qu[rear]=data;
        pr[rear]=prior;
    }
    else if(rear==max-1)
    {
        for(int i=front;i<=rear;i++)
        {
            qu[i=front]
        }
    }
}
int main()
{


}
