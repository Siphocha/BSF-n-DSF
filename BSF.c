#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 13

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

Node* graph[MAX_VERTICES];
int visited[MAX_VERTICES];

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(Queue* q) {
    //This one is definitely not empty BUT still.
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    //Put that numeric in the q
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    //function for taking out of the queues.
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph[src];
    graph[src] = newNode;
    
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

void BFS(int startVertex) {
    Queue* q = createQueue();
    
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    while (!isEmpty(q)) {
        int currVertex = dequeue(q);
        printf("%d ", currVertex);
        Node* temp = graph[currVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

void initializeGraph() {
    //Data points coming from the discussion forum.
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
    //Internal grpah for mapping it out
    initializeGraph();
    
    printf("BFS Traversing:");
    for (int i = 1; i < MAX_VERTICES; i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }
    printf("\n");
    return 0;
}