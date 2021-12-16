#include<stdio.h>
#include<conio.h>

int n;
int matr[20][20];
int visited[20];

void DFS(int i) {
    printf("%d ", i);
    visited[i] = 1;

    for(int j=0; j<n; j++) {
        if(matr[i][j]==1 && visited[j] == 0) {
            DFS(j);
        }
    }
}

void main() {
    int i;

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

    for(int i=0; i<20; i++) {
        visited[i] = 0;
    }

    DFS(i);
}