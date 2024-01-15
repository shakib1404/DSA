#include<stdio.h>
#include<stdbool.h>

int v;
int graph[20][20];
int queue[20];
int numberofelement=0;
int rear=-1, front=-1;
int visited[20],prev[20],d[20];
int white=-3,gray=-2,black=-1;


bool isEmpty()
{
    return (numberofelement==0);
}
bool isFull()
{
    return (numberofelement==20);

}
void enqueue(int x)
{
    if(isFull())
    {
        printf("queue is full");
        return;

    }
    if(front==-1)
        front=0;

        rear++;
       queue[rear] =x;
       numberofelement++;
}

int dequeue()
{
    if(isEmpty())
    {
        printf("queue is empty");
        return -1;
    }

    int x=queue[front];
    front++;
    numberofelement--;

    return x;

}

void bfs(int s)
{
    for(int i=0;i<v;i++)
    {
        visited[i]=white;
        prev[i]=-8;
        d[i]=-9;
    }
    visited[s]=gray;
    d[s]=0;
    prev[s]=-8;
    enqueue(s);

    printf("visiting starting from %d:",s);

    while(!isEmpty())
    {
        int u=dequeue();

        printf("%d ",u);
        for(int i=0;i<v;i++)
        {
            if(graph[u][i]==1 && visited[i]==white){
                visited[i]=gray;
              d[i]=d[u]+1;
              prev[i]=u;
              enqueue(i);
            }

        }
        visited[u]=black;
    }
}





int main()
{
    printf("take the number of vertics:");

    scanf("%d",&v);

    int e;

    printf("take the numberofedges:");

    scanf("%d",&e);

    for(int i=0;i<e;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
    }

    bfs(0);


    return 0;
}
