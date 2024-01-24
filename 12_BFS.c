#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

int queue[MAX_VERTICES], front = -1, rear = -1, visited[MAX_VERTICES];
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], vertices;

void enqueue(int vertex) {
    queue[++rear] = vertex;
    visited[vertex] = 1;
}

int dequeue() {
    return queue[front++];
}

void BFS() {
    int currentVertex;
    enqueue(0);

    while (front <= rear) {
        currentVertex = dequeue();
        printf("Traversed: %d\n", currentVertex);

        for (int i =0; i<vertices;i++) {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
                enqueue(i);
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d",&adjacencyMatrix[i][j]);
        }
    }

    BFS();

    return 0;
}