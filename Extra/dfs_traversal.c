#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int num_vertices;

void init_graph()
{
    int i, j;
    num_vertices = 0;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(int i, int j)
{
    adj_matrix[i][j] = 1;
    adj_matrix[j][i] = 1;
    if (i > num_vertices)
        num_vertices = i;
    if (j > num_vertices)
        num_vertices = j;
}

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 1; i <= num_vertices; i++)
    {
        if (adj_matrix[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void display()
{
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 1; i <= num_vertices; i++)
    {
        for (j = 1; j <= num_vertices; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j, num_edges, start_node;

    init_graph();

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    // Input edges
    for (int k = 0; k < num_edges; k++)
    {
        printf("Enter edge (i, j): ");
        scanf("%d %d", &i, &j);
        add_edge(i, j);
    }

    display();

    printf("Enter the starting node for DFS traversal: ");
    scanf("%d", &start_node);

    for (i = 1; i <= num_vertices; i++)
    {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(start_node);
    printf("\n");

    return 0;
}
