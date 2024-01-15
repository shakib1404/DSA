#include <graphics.h>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>
#include<conio.h>
using namespace std;

const int MAX_NODES = 6;

struct Node {
    int x, y;
};

void visualizeGraph(const vector<Node>& nodes, const vector<vector<int>>& adjacencyList, int currentNode) {
    cleardevice();

    // Draw edges
    for (int i = 0; i < adjacencyList.size(); ++i) {
        for (int neighbor : adjacencyList[i]) {
            line(nodes[i].x, nodes[i].y, nodes[neighbor].x, nodes[neighbor].y);
        }
    }

    // Draw nodes
    for (int i = 0; i < nodes.size(); ++i) {
        circle(nodes[i].x, nodes[i].y, 20);
        char label[2];
        sprintf(label, "%d", i);
        outtextxy(nodes[i].x - 5, nodes[i].y - 5, label);
    }

    // Highlight current node
    setcolor(RED);
    circle(nodes[currentNode].x, nodes[currentNode].y, 22);
    setcolor(WHITE);
}

void BFS(const vector<vector<int>>& adjacencyList, const vector<Node>& nodes, int startNode) {
    queue<int> q;
    vector<bool> visited(MAX_NODES, false);

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        visualizeGraph(nodes, adjacencyList, currentNode);
        delay(500);

        for (int neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    vector<Node> nodes = {{100, 100}, {200, 100}, {300, 100}, {100, 200}, {200, 200}, {300, 200}};
    vector<vector<int>> adjacencyList = {{1, 3}, {0, 4}, {4, 5}, {0}, {1, 2}, {2}};

    int startNode = 0;
    BFS(adjacencyList, nodes, startNode);

    delay(50000);
    closegraph();
    getch();

    return 0;
}
