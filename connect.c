#include<stdio.h>

typedef struct{
    int u;
    int v;
}edge;
typedef struct{
    int a;
    int b;
}node;

node visited[100];

void dfs(edge arr[], int n,int x,int type)
{
    visited[x].a=1;
    visited[x].b=type;
    for(int i=0;i<n;i++)
    {
        if(arr[i].u==x &&visited[arr[i].v].a==0)
        {
            dfs(arr,n,arr[i].v,type);
        }
    }
}

void main()
{
    int n,m,type=0;
    scanf("%d %d",&n,&m);
    edge arr[2*m];
    for(int i=0;i<2*m;i+=2)
    {
        scanf("%d %d", &arr[i].u,&arr[i].v);
        arr[i+1].u=arr[i].v;
        arr[i+1].v=arr[i].u;
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i].a==0)
        {
            dfs(arr,2*m,i,type);
            type++;
        }
    }
    printf("%d",type);
}