#include <iostream>
#include <vector>

struct node {
  int vertex;
  node* next;
};

struct Graph {
  int numVertices;
  int* visited;
  node** adjLists;
};

node* createNode(int v) {
  node* newNode = new node;
  newNode->vertex = v;
  newNode->next = nullptr;
  return newNode;
}

void DFS(Graph* graph, int vertex) {
  node* adjList = graph->adjLists[vertex];
  node* temp = adjList;

  graph->visited[vertex] = 1;
  std::cout << "Visited " << vertex << std::endl;

  while (temp != nullptr) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

Graph* createGraph(int vertices) {
  Graph* graph = new Graph;
  graph->numVertices = vertices;

  graph->adjLists = new node*[vertices];
  graph->visited = new int[vertices];

  for (int i = 0; i < vertices; i++) {
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

void printGraph(Graph* graph) {
  for (int v = 0; v < graph->numVertices; v++) {
    node* temp = graph->adjLists[v];
    std::cout << "\n Adjacency list of vertex " << v << "\n ";
    while (temp) {
      std::cout << temp->vertex << " -> ";
      temp = temp->next;
    }
    std::cout << "\n";
  }
}

int main() {
  Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  DFS(graph, 2);

  delete[] graph->adjLists;
  delete[] graph->visited;
  delete graph;

  return 0;
}

