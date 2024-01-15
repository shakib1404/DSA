#include <iostream>
#include <queue>
#include <graphics.h>


using namespace std;


const int WIDTH = 800;
const int HEIGHT = 600;
const int NODE_RADIUS = 30;


struct Node {
    int x, y;
    bool visited;
};

void drawNode(Node node) {
    circle(node.x, node.y, NODE_RADIUS);
    node.visited = true;
    floodfill(node.x, node.y, WHITE);
}

void drawEdge(Node node1, Node node2) {
    line(node1.x, node1.y, node2.x, node2.y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Node nodes[5];
    nodes[0] = {100, 100, false};
    nodes[1] = {200, 200, false};
    nodes[2] = {300, 100, false};
    nodes[3] = {400, 200, false};
    nodes[4] = {500, 100, false};

    drawNode(nodes[0]);
    drawNode(nodes[1]);
    drawNode(nodes[2]);
    drawNode(nodes[3]);
    drawNode(nodes[4]);

    drawEdge(nodes[0], nodes[1]);
    drawEdge(nodes[1], nodes[2]);
    drawEdge(nodes[1], nodes[3]);
    drawEdge(nodes[2], nodes[4]);

    queue<Node> bfsQueue;
    bfsQueue.push(nodes[0]);

    while (!bfsQueue.empty()) {
        Node currentNode = bfsQueue.front();
        bfsQueue.pop();

        for (int i = 0; i < 5; ++i) {
            if (!nodes[i].visited && currentNode != nodes[i]) {
                drawEdge(currentNode, nodes[i]);
                drawNode(nodes[i]);
                bfsQueue.push(nodes[i]);
            }
        }
    }

    delay(5000);
    closegraph();
    return 0;
}
