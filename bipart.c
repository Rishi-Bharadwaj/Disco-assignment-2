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
int flag=0;
int runcount=0;

void bfs(edge arr[],int n,node *ancestors,int acount,int x,int type)
{
    runcount++;
    visited[x].a=1;
    visited[x].b=type;
    for(int i=0;i<n;i++)
    {
        if(arr[i].u==x && visited[arr[i].v].a==0)
        {
            ancestors[acount].a=arr[i].v;
            if(type==0)
            ancestors[acount].b=0;
            else ancestors[acount].b=1;
            acount++;
        }
        else if(arr[i].u==x && visited[arr[i].v].b==type)
        {
            flag=1;
        }
    }
    if(ancestors[runcount].a!=0 && ancestors[runcount].b==0)
    {
        bfs(arr,n,ancestors,acount,ancestors[runcount].a,1);
    }
    else if(ancestors[runcount].a!=0 && ancestors[runcount].b==1)
    {
        bfs(arr,n,ancestors,acount,ancestors[runcount].a,0);
    }

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
    ancestors[0].b=0;
    bfs(arr,2*n,ancestors,1,1,0);
    if(flag==0)
    printf("YES");
    else
    printf("NO");
}
