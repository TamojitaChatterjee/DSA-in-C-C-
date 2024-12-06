//graph- adjacency list
#include <stdio.h>
#include <stdlib.h>

class Node {
public:
    int vertex;
    Node* next;

    Node(int v) {
        vertex = v;
        next = NULL;
    }
};

class Graph {
private:
    Node** adjList;
    int numVertices;

public:
    Graph(int vertices) {
        numVertices = vertices;

        // Allocate memory for adjacency list
        adjList = (Node**)malloc(vertices * sizeof(Node*));
        for (int i = 0; i < vertices; i++) {
            adjList[i] = NULL;
        }
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            printf("Invalid edge!\n");
            return;
        }

        Node* newNode = new Node(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        // For undirected graph
        newNode = new Node(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;

        printf("Edge added between %d and %d.\n", u, v);
    }

    // Display the adjacency list
    void display() {
        printf("Adjacency List:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("%d: ", i);
            Node* temp = adjList[i];
            while (temp != NULL) {
                printf("%d -> ", temp->vertex);
                temp = temp->next;
            }
            printf("NULL\n");
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
        printf("2. Display Graph\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter vertices (u v) to add edge: ");
            scanf("%d %d", &u, &v);
            g.addEdge(u, v);
            break;

        case 2:
            g.display();
            break;

        case 3:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}