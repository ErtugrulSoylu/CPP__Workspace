#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#define N 12

int graph[N][N] = {//adjacency matrix of nodes
//   A,B,C,D,E,F,G,H,I,J,K,L
    {0,1,0,0,0,0,0,0,0,1,1,0},//A
    {0,0,0,0,0,0,0,0,1,0,0,0},//B
    {0,0,0,1,0,0,0,0,0,0,0,0},//C
    {0,0,0,0,0,1,0,0,0,0,0,0},//D
    {1,0,0,0,0,0,0,0,0,0,0,0},//E
    {0,0,0,0,0,0,0,1,0,0,0,1},//F
    {0,1,0,0,0,0,0,1,0,0,0,0},//G
    {0,0,0,1,0,0,0,0,0,0,0,0},//H
    {0,0,0,0,0,1,0,0,0,0,1,0},//I
    {0,0,1,1,0,0,0,0,0,0,0,0},//J
    {0,0,0,0,1,0,1,0,0,0,0,0},//K
    {0,0,0,0,0,0,1,0,1,0,0,0},//L
};
char node[N] = {//node names
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'
};
int S_node, E_node;//Starting Node and Ending Node indexes
int DFS(int x, int y, int visited[N], char path[100], int index) {//DFS Recursive algorithm
    visited[x] = 1;
    path[index] = node[x];
    if(x == y) {//when current location meets destination writes path on screen
        for(int i = 0; i < strlen(path); i++) printf("%c   ", path[i]);
        return 1;
    }
    for(int i = 0; i < N; i++) {//loop to check adjacency nodes
        if(graph[x][i] && !visited[i])
            if(DFS(i, y, visited, path, index+1)) return 1;//if finds such a solution returns to avoid other solutions
    }
    return 0;
}

int main() {
    printf("RECURSIVE DEPTH-FIRST SEARCH METHOD\n\nN4ODES IN DIRECTED GRAPH:\n");
    for(int i = 0; i < N; i++) printf(" %d. %c\n", i+1, node[i]);
    printf("Enter numbers of Starting and Ending nodes : ");
    scanf("%d", &S_node);
    scanf("%d", &E_node);
    printf("\n\nSOLUTION PATH =\n");
    int visited[N] = {0,0,0,0,0,0,0,0,0,0,0,0};//temporary visited nodes
    char path[100] = "";//temporary path
    DFS(S_node-1, E_node-1, visited, path, 0);
    return 0;
}