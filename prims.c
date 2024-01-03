#include<stdio.h>

typedef struct{
    int u;
    int v;
    int cost;
}edge;

int visited[100];
edge mst[100];
int mcount=0;

void form(edge arr[],int n,int m)
{
    edge min;
    min.cost=10000;
    for(int i=1;i<=m;i++)
    {
        if(visited[i])
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j].u==i && !visited[arr[j].v] && arr[j].cost<min.cost)
                {
                    mst[mcount].u=arr[j].u;
                    mst[mcount].v=arr[j].v;
                    mst[mcount].cost=arr[j].cost;
                    min.cost=arr[j].cost;
                }
            }
        }
    }
    visited[mst[mcount].v]=1;
    mcount++;
}

void main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    edge arr[2*m];
    for(int i=0;i<2*m;i+=2)
    {
        scanf("%d %d %d",&arr[i].u,&arr[i].v,&arr[i].cost);
        arr[i+1].u=arr[i].v;
        arr[i+1].v=arr[i].u;
        arr[i+1].cost=arr[i].cost;
    }
    visited[1]=1;
    
    int k=0;
    while(k<n-1)
    {
        form(arr,2*m,n);
        k++;
    }
    int total=0;
    for(int i=0;i<mcount;i++)
    {
        total+=mst[i].cost;
    }
    printf("%d ",total);
}