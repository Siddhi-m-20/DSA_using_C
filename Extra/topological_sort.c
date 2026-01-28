#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node {
    int vertex;
    struct node *next;
} node_t;

node_t *graph[MAX_VERTICES];
int visited[MAX_VERTICES];
int topo_order[MAX_VERTICES], n;

node_t *create_node(int v) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

void add_edge(int u, int v) {
    node_t *new_node = create_node(v);
    new_node->next = graph[u];
    graph[u] = new_node;
}

void dfs(int v) {
    visited[v] = 1;
    node_t *adj_list = graph[v];
    while (adj_list != NULL) {
        int adj_vertex = adj_list->vertex;
        if (!visited[adj_vertex]) {
            dfs(adj_vertex);
        }
        adj_list = adj_list->next;
    }
    topo_order[--n] = v;
}

void topological_sort(int num_vertices) {
    n = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
        topo_order[i] = -1;
    }
    for (int i = 1; i <= num_vertices; i++) {
        if (!visited[i]) {
            dfs(i);
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
        graph[i] = NULL;
    }

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        printf("Enter the endpoints of edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    topological_sort(num_vertices);

    printf("Topological order: ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", topo_order[i]);
    }
    printf("\n");

    return 0;
}
