#include <iostream>
#include<stdio.h>


using namespace std;

const int SIZE = 40;

struct node {
  int vertex;
  node* next;
};

struct Graph {
  int numVertices;
  node* adjLists[SIZE];
  int visited[SIZE];
};

struct queue {
  int front;
  int rear;
  int items[SIZE];
};

queue* createQueue() {
  queue* q = new queue;
  q->front = -1;
  q->rear = -1;
  return q;
}

void enqueue(queue* q, int value) {
  if (q->rear == -1)
    q->front = 0;
  q->rear++;
  q->items[q->rear] = value;
}

int dequeue(queue* q) {
  int item;
  if (q->front > q->rear) {
    std::cout << "Resetting queue ";
    q->front = q->rear = -1;
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
  }
  return item;
}

bool isEmpty(queue* q) {
  return q->rear == -1;
}

node* createNode(int v) {
  node* newNode = new node;
  newNode->vertex = v;
  newNode->next = nullptr;
  return newNode;
}

Graph* createGraph(int vertices) {
  Graph* graph = new Graph;
  graph->numVertices = vertices;

  for (int i = 0; i < SIZE; ++i) {
    graph->adjLists[i] = nullptr;
    graph->visited[i] = 0;
  }

  return graph;
}

void addEdge(Graph* graph, int src, int dest) {
  // Add edge from src to dest
  node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void bfs(Graph* graph, int startVertex) {
  queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    int currentVertex = dequeue(q);
    std::cout << "Visited " << currentVertex << std::endl;

    node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

int main() {
  Graph* graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  bfs(graph, 0);

  delete graph; // Don't forget to release allocated memory
  return 0;
}
