//graph-adjacency matrix 
#include <stdio.h>
#include <stdlib.h>

class Graph {
private:
    int** adjMatrix;
    int numVertices;

public:
    Graph(int vertices) {
        numVertices = vertices;

        // Allocate memory for adjacency matrix
        adjMatrix = (int**)malloc(vertices * sizeof(int*));
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = (int*)calloc(vertices, sizeof(int)); // Initialize with 0
        }
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            printf("Invalid edge!\n");
            return;
        }
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Comment this line for directed graph
        printf("Edge added between %d and %d.\n", u, v);
    }

    // Remove an edge from the graph
    void removeEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            printf("Invalid edge!\n");
            return;
        }
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0; // Comment this line for directed graph
        printf("Edge removed between %d and %d.\n", u, v);
    }

    // Display the adjacency matrix
    void display() {
        printf("Adjacency Matrix:\n");
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                printf("%d ", adjMatrix[i][j]);
            }
            printf("\n");
        }
    }
};

// Menu-driven main function
int main() {
    int vertices, choice, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph g(vertices);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Remove Edge\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter vertices (u v) to add edge: ");
            scanf("%d %d", &u, &v);
            g.addEdge(u, v);
            break;

        case 2:
            printf("Enter vertices (u v) to remove edge: ");
            scanf("%d %d", &u, &v);
            g.removeEdge(u, v);
            break;

        case 3:
            g.display();
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}