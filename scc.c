    #include<stdio.h>
#include<string.h>
#include<stdbool.h>

int n;
int graph[20][20];
int stack[20],ptr=-1;
int visited[20];

void push(int x)
{
    ptr++;
    stack[ptr]=x;
}

bool isEmpty(){

return (ptr==-1);


}

int top()
{
    return stack[ptr];
}

void pop()
{
    ptr--;
}

dfs(int i)
{
    if(visited[i])
        return;
    visited[i]=0;

    for(int j=0;j<n;j++)
    {
        if(graph[i][j])
        {
            dfs(j);
        }
    }
    push(i);
}
dfsinverse(int i)
{
    if(visited[i])
        return;
    visited[i]=1;

    for(int j=0;j<n;j++)
    {
        if(graph[j][i])
            dfsinverse(j);
    }
}

int main()
{
    printf("take the vertics:");
    scanf("%d",&n);

    int e;
    printf("take the edges:");

    for(int i=0;i<e;i++)
    {
        int a,b;
        scanf("%d &d",&a,&b);
        graph[a][b]=1;
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            dfs(i);
    }

    for(int i=0;i<n;i++)
        visited[i]=0;

    printf("Strongly connected components:");
    int cnt=0;

    while(!isEmpty())
    {
        int v=top();
        pop();

        if(visited[v]==0)
        {
            dfsinverse(v);
            printf("\n");
    cnt++;

        }
    }
    printf("number of strongly connected components: %d\n",cnt);
    return 0;
}
