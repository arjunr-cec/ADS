#include<stdio.h>

void dfs(int);

int graph[10][10], visited[10], vertices;

int main() {
    int i, j;

    printf("Enter the number of vertices:");
    scanf("%d", &vertices);

    printf("Enter the adjacent matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("\nDFS traversal: ");
    dfs(0);

    return 0;
}

void dfs(int vertex) {
    int j;
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (j = 0; j < vertices; j++) {
        if (!visited[j] && graph[vertex][j]) {
            dfs(j);
        }
    }
}
