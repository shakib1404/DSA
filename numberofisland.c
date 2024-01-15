#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define row 5
#define col 5
int count=0;

int visited[col];
int graph[row][col]=
{ { 1, 1, 0, 0, 0 },
{ 0, 1, 0, 0, 1 },
{ 1, 0, 0, 1, 1 },
{ 0, 0, 0, 0, 0 },
{ 1, 0, 1, 0, 1 }
};

void dfs(int i)
{
    if (visited[i])
        return;
    visited[i]=1;


    for(int j=0;j<5;j++)
    {
        if(graph[i][j])
        {
            //count++;
            dfs(j);

        }
       // count++;
    }
    count++;

}

int main()
{
for(int i=0;i<5;i++)
{
    if( visited[i]==0)
        dfs(i);
}
printf("%d",count);
}
