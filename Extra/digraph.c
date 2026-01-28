#include <stdio.h>
#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void initialize_graph(int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(int u, int v, int is_directed) {
    if (is_directed) {
        adj_matrix[u][v] = 1;  // For directed graph
    } else {
        adj_matrix[u][v] = 1;  // For undirected graph
        adj_matrix[v][u] = 1;  // For undirected graph
    }
}


void print_graph(int num_vertices, int is_directed) {
    printf("Adjacency Matrix:\n\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    if (!is_directed) {
        printf("\nDegree of each vertex:\n\n");
        for (int i = 0; i < num_vertices; i++) {
            int degree = 0;
            for (int j = 0; j < num_vertices; j++) {
                degree += adj_matrix[i][j];
            }
            printf("Vertex %d: %d\n", i, degree);
        }
    } else {
        printf("\nIn-Degree and Out-Degree of each vertex:\n\n");
        for (int i = 0; i < num_vertices; i++) {
            int in_degree = 0, out_degree = 0;
            for (int j = 0; j < num_vertices; j++) {
                in_degree += adj_matrix[j][i];
                out_degree += adj_matrix[i][j];
            }
            printf("Vertex %d: In-Degree = %d, Out-Degree = %d\n", i, in_degree, out_degree);
        }
    }
}

int main() {
    int num_vertices, num_edges, is_directed;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Is the graph directed? (1 for yes, 0 for no): ");
    scanf("%d", &is_directed);

    initialize_graph(num_vertices);

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        printf("Enter the endpoints of edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        add_edge(u, v, is_directed);
    }

    print_graph(num_vertices, is_directed);

    return 0;
}
