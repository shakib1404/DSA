#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int n;
int graph[20][20];
int visited[20];
int indegree[20];

dfs(int i)
{
    if(visited[i])
        return;
        visited[i]=1;

        printf("%d ",i);

        for(int j=0;j<n;j++)
        {
            if(graph[i][j])
            {
                indegree[j]--;

                if(indegree[j]==0)
                    dfs(j);
            }
        }

}


int main()
{
    printf("take the vertices:");
    scanf("%d",&n);

    int e;
    printf("take the edges:");
    scanf("%d ",&e);

    memset(indegree,0,20);
    memset(visited,0,20);
    memset(graph,0,sizeof(graph));

    for(int i=0;i<e;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        graph[a][b]=1;
        indegree[b]++;
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            dfs(i);
    }

  return 0;
}

