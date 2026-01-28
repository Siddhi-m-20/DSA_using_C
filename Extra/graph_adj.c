#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct graph {
    int num_vertices;
    struct node** adj_list;
};

struct node* create_node(int v) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

struct graph* create_graph(int num_vertices) {
    struct graph* new_graph = (struct graph*) malloc(sizeof(struct graph));
    new_graph->num_vertices = num_vertices;
    new_graph->adj_list = (struct node**) malloc(num_vertices * sizeof(struct node*));
    int i;
    for (i = 0; i < num_vertices; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

void add_edge(struct graph* g, int src, int dest) {
    struct node* new_node = create_node(dest);
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;

    new_node = create_node(src);
    new_node->next = g->adj_list[dest];
    g->adj_list[dest] = new_node;
}

void print_graph(struct graph* g) {
    int v;
    for (v = 0; v < g->num_vertices; v++) {
        struct node* tmp = g->adj_list[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (tmp) {
            printf("-> %d", tmp->vertex);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main() {
    int num_vertices, num_edges, i, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    struct graph* graph = create_graph(num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);


    for (i = 0; i < num_edges; i++) {
        printf("Enter source and destination of edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        add_edge(graph, src, dest);
    }

    print_graph(graph);

    return 0;
}
