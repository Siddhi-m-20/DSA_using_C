#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

typedef struct {
    int data[MAX_NODES];
    int top;
} Stack;

void push(Stack *s, int node) {
    s->data[++s->top] = node;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void dfs(int start_node, int num_nodes) {
    Stack stack;
    stack.top = -1;

    push(&stack, start_node);
    visited[start_node] = 1;

    while (!is_empty(&stack)) {
        int current_node = pop(&stack);
        printf("%d -> ", current_node);

        for (int i = 1; i <= num_nodes; i++) {
            if (graph[current_node][i] == 1 && !visited[i]) {
                push(&stack, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int num_nodes, start_node;
    
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node for DFS traversal: ");
    scanf("%d", &start_node);

    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nDFS Traversal from node %d:\n", start_node);
    dfs(start_node, num_nodes);

    return 0;
}
