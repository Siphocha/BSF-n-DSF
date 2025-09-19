#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 13 
//This means 0-12

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX_VERTICES];
int visited[MAX_VERTICES];

void addEdge(int src, int undir) {
    //Add edges node to node.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = undir;
    newNode->next = graph[src];
    graph[src] = newNode;
    
    //Undirected graph procedure
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph[undir];
    graph[undir] = newNode;
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    Node* temp = graph[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

void initializeGraph() {
    //Add edges based on your graph structure
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 6);
    addEdge(5, 7);
    addEdge(5, 8);
    addEdge(6, 9);
    addEdge(8, 10);
    addEdge(9, 11);
    addEdge(9, 12);
}

int main() {
    initializeGraph();
    printf("DFS Traversal:");
    for (int i = 1; i < MAX_VERTICES; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    printf("\n");
    return 0;
}