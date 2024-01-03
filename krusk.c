#include<stdio.h>

typedef struct{
    int u;
    int v;
    int cost;
}edge;

int visited[100];
edge mst[100];
int mcount=0;
int cyccheck;
int vis2[100];
int rc;

void cycle(edge arr[],int n,int x,int ori)
{
    vis2[x]=1;
    if(x==ori && rc)
    {
        cyccheck=1;        
    }
    rc++;
    for(int i=0;i<n;i++)
    {
        if(arr[i].u==x && visited[arr[i].v] && !vis2[arr[i].v])
        {
            cycle(arr,n,arr[i].v,ori);
        }
    }
}

void form(edge arr[],int n)
{
    edge min;
    min.cost=10000;
    for(int i=0;i<n;i++)
    {
        rc=0,cyccheck=0;
        for(int p=0;p<100;p++)
        vis2[p]=0;
        cycle(arr,n,arr[i].v,arr[i].v);
        if(arr[i].cost<min.cost &&  !(cyccheck))
        {
            min.cost=arr[i].cost;
            mst[mcount].u=arr[i].u;
            mst[mcount].v=arr[i].v;
            mst[mcount].cost=arr[i].cost;
        }
    }
    printf("mst[mcount].u: %d\n",mst[mcount].u);
    printf("mst[mcount].v: %d\n",mst[mcount].v);
    visited[mst[mcount].v]=1;
    visited[mst[mcount].u]=1;
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
    
    int k=0;
    while(k<n-1)
    {
        form(arr,2*m);
        k++;
    }
    int total=0;
    for(int i=0;i<mcount;i++)
    {
        total+=mst[i].cost;
    }
    printf("%d ",total);
    printf("%d", mcount);
}

