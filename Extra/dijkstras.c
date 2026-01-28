#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES],visited[MAX_VERTICES];

int find_min_distance(int num_vertices) {
    int min_distance = INT_MAX, min_vertex;
    for (int v = 0; v < num_vertices; v++) {
        if (!visited[v] && dist[v] < min_distance) {
            min_distance = dist[v];
            min_vertex = v;
        }
    }
    return min_vertex;
}

void dijkstra(int start_vertex, int num_vertices) {
    for (int v = 0; v < num_vertices; v++) {
        dist[v] = INT_MAX;
        visited[v] = 0;
    }
    dist[start_vertex] = 0;

    for (int i = 0; i < num_vertices - 1; i++) {
        int u = find_min_distance(num_vertices);
        visited[u] = 1;

        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        printf("Enter the endpoints of edge %d and its weight: ", i+1);
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // if the graph is undirected
    }

    int start_vertex;
    printf("Enter the source vertex: ");
    scanf("%d", &start_vertex);

    dijkstra(start_vertex, num_vertices);

    printf("Shortest path distances from vertex %d:\n", start_vertex);
    for (int v = 0; v < num_vertices; v++) {
        printf("Vertex %d: ", v);
        if (dist[v] == INT_MAX) {
            printf("inf\n");
        } else {
            printf("%d\n", dist[v]);
        }
    }

    return 0;
}
