#include<stdio.h>

int visited[100];
int runcount=0;

typedef struct{
    int u;
    int v;
}edge;

typedef struct{
    int a;
    int b;
}node;

void bfs(edge arr[], int n, int x, node * ancestors,int acount,int degree)
{
    runcount++;
    visited[x]=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i].u==x && visited[arr[i].v]==0)
        {
            ancestors[acount].a=arr[i].v;
            ancestors[acount].b=degree+1;
            acount++;
        }
    }
    if(ancestors[runcount].a!=0)
    bfs(arr,n,ancestors[runcount].a,ancestors,acount,ancestors[runcount].b);

}


void main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    edge arr[2*n];
    for(int i=0;i<2*n;i+=2)
    {
        scanf("%d %d",&arr[i].u,&arr[i].v);
        arr[i+1].u=arr[i].v;
        arr[i+1].v=arr[i].u;
    }
    node ancestors[100]={0};
    ancestors[0].a=1;
    ancestors[0].b=1;
    bfs(arr,2*n,1,ancestors,1,1);
    int y=m;
    int i=0;
    int min=100;
    while(ancestors[i].a!=0)
    {
        if(ancestors[i].a==y && ancestors[i].b<min)
        {
            min=ancestors[i].b;
        }
        i++;
    }
    printf("%d",min-1);
}