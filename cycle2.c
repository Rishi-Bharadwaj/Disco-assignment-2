#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int u;
    int v;
}edge;

int visited[100];
int ans;

void dfs(int x,edge arr[],int n,int * path, int pcount)
{
    visited[x]=1;
    path[pcount++]=x;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i].u==x && visited[arr[i].v]==0)
        {
            dfs(arr[i].v,arr,n,path,pcount);
        }
        else if(arr[i].u==x)
        {
            for(int j=0;j<pcount-2;j++)
            {
                if(path[j]==arr[i].v)
                {
                    ans=1;
                    for(int l=j;l<pcount;l++)
                    {
                        printf("%d ",path[l]);
                    }
                    exit(1);
                }
            }
        }
    }
}

void main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    edge arr[2*m];
    for(int i=0;i<2*m;i+=2)
    {
        scanf("%d %d", &arr[i].u,&arr[i].v);
        arr[i+1].u=arr[i].v;
        arr[i+1].v=arr[i].u;
    }
    int path[100];
    for(int i=0;i<100;i++)
    {
        path[i]=0;
    }

    dfs(1,arr,2*m,path,0);
    if(ans==0) printf("%d",-1);
}