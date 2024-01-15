#include <stdio.h>

#define MAX_VERTICES 20

int n;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES], prev[MAX_VERTICES], f[MAX_VERTICES], d[MAX_VERTICES];
int time;
int white = -1;
int gray = -2;
int black = -3;

void dfsvisit(int l);

void dfs() {
    for (int i = 0; i < n; i++) {
        color[i] = white;
        prev[i] = -5;
        f[i] = -6;
        d[i] = -7;
    }

    time = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == white)
            dfsvisit(i);
    }
}

void dfsvisit(int l) {
    color[l] = gray;
    time = time + 1;
    d[l] = time;
    printf("%d ", l);

    for (int i = 0; i < n; i++) {
        if (color[i] == white && graph[l][i]==1) {
            prev[i] = l;
            dfsvisit(i);
        }
    }

    color[l] = black;
    time = time + 1;
    f[l] = time;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int e;
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        int a, b;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;  // Assuming the graph is undirected
        graph[b][a] = 1;
    }

    dfs();
    for (int i = 0; i < n; i++)
        printf("Visiting time %d|%d\n", d[i], f[i]);

    return 0;
}
