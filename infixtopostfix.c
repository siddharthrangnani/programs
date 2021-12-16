#include<stdio.h>
#include<conio.h>
char stack[30];
int top==-1;
void insert(char x)
{
    stack[top++]=x;
}
void pop()
{   if(top!=-1)
        {
            return stack[top--];
        }

}
int prior(char sym)
    {
        if(sym=="^")
            return 3;
        else if(sym=="+" && sym=="-")
            return 1;
        else if(sym=="*"&&sym=="/")
            return 2;
            else
        {
            return 0;
        }
    }
int main()
{
    char s[30],out[30];
    printf("enter string");
    scanf("%s",s);
    while(s!=NULL)
    {
        if(alnum)
    }

}
