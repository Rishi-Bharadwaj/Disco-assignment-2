#include<stdio.h>
#include<stdlib.h>
int visited[1000];
int viscount=0;
int pcount=0;
struct edge{
    int u;
    int v;
};
typedef struct edge edge;

int in(int x, int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        return 1;
    }
    return 0;
}

int dfs( int x, int y, edge arr[], int n, int * path)
{
    visited[viscount++]=x;
    path[pcount++]=x;
    if(x==y)
        {
            return 1;
        }
    for(int i=0;i<n;i++)
    {
        if(arr[i].u==x &&!in(arr[i].v,visited,viscount))
        {
            if (dfs(arr[i].v,y,arr,n,path))
            {
                return 1;
            }
        }
    }
    pcount--;
    return 0;
}

void main()
{
    int n;
    scanf("%d",&n);
    edge arr[2*(n-1)];
    for(int i=0;i<2*(n-1);i+=2)
    {
        scanf("%d %d",&arr[i].u,&arr[i].v);
        arr[i+1].u=arr[i].v;
        arr[i+1].v=arr[i].u;
    }
    int x,y;
    scanf("%d %d",&x,&y);
    int path[100]={0};
    dfs(x,y,arr,2*n,path);
    printf("%d\n",pcount);
    for(int i=0;i<pcount;i++)
    {
        printf("%d ",path[i]);
    }
}