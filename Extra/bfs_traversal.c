#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}

void bfs_traversal(int start_vertex, int num_vertices) {
    int i, vertex;
    for (i = 0; i < num_vertices; i++) {
        visited[i] = 0;
    }
    visited[start_vertex] = 1;
    enqueue(start_vertex);
    while (front <= rear) {
        vertex = dequeue();
        printf("%d ", vertex);
        for (i = 0; i < num_vertices; i++) {
            if (graph[vertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int num_vertices, num_edges, i, j, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < num_edges; i++) {
        printf("Enter the endpoints of edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("\nThe adjacency matrix is:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the starting vertex for BFS traversal: ");
    scanf("%d", &u);

    printf("\nThe BFS traversal is:\n");
    bfs_traversal(u, num_vertices);

    return 0;
}
