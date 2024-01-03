#include<stdio.h>

int runcount=0;
typedef struct{
    int u;
    int v;
}edge;
typedef struct{
    int a;
    int b;
}node;

int visited[100];
int lub(edge arr[],int n, int x, int y);
int glb(edge arr[], int n, int x, int y);

void bfs(int x,edge arr[], int n,int acount,node* ancestors,int degree)
{
    visited[x]=1;
    runcount++;
    for(int i=0;i<n;i++)
    {
        if(arr[i].v==x && !(visited[arr[i].u]))
        {
            ancestors[acount].a=arr[i].u;
            ancestors[acount++].b=degree+1;
        }
    }
    if(ancestors[runcount].a!=0)
    bfs(ancestors[runcount].a,arr,n,acount,ancestors,ancestors[runcount].b);
}


void main()
{
    int n, m ,x ,y;
    scanf("%d %d %d %d", &n,&m,&x,&y);
    edge arr[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&arr[i].u,&arr[i].v);
    }
    int g = glb(arr,m,x,y);
    int l = lub(arr,m,x,y);
    printf("%d %d",g,l);
}

int glb(edge arr[],int m, int x, int y)
{
    node ancestors[100];
    for(int k=0;k<100;k++)
    {
        visited[k]=0;
        ancestors[k].a=0;
        ancestors[k].b=0;
    }
    int acount=0;
    ancestors[acount].a=x;
    ancestors[acount++].b=1;
    runcount=0;
    bfs(x,arr,m,acount,ancestors,1);

    node ya[100];
    for(int k=0;k<100;k++)
    {
        visited[k]=0;
        ya[k].a=0;
        ya[k].b=0;
    }

    int ycou=0;
    ya[ycou].a=y;
    ya[ycou++].b=1;
    runcount=0;
    bfs(y,arr,m,ycou,ya,1);
    
    int p=0;
    int ans=0;
    int degree=0;
    while(ancestors[p].a!=0)
    {
        int q=0;
        while(ya[q].a!=0)
        {
            if(ancestors[p].a==ya[q].a && ancestors[p].b!=ya[q].b)
            {

                return ya[q].a;
            }
            else if(ancestors[p].a==ya[q].a && ancestors[p].b==ya[q].b)
            {
                ans=ya[q].a;
                degree=ya[q].b;
                int g=0,h=0;
                while(ancestors[g].a!=0)
                {
                    h=0;
                    while(ya[h].a!=0)
                    {
                        if(ancestors[g].a==ya[h].a && ancestors[g].b==ya[h].b &&ya[h].b==degree && ya[h].a!=ans)
                        return -1;
                        h++;
                    }
                    g++;
                }
                return ans;
            }
            q++;
        }
        p++;
    }
    return -1;
  
}
int lub(edge arr[],int n, int x, int y)
{
    edge rev[n];
    for(int i=0;i<n;i++)
    {
        rev[i].u=arr[n-i-1].v;
        rev[i].v=arr[n-i-1].u;
    }
    for(int i=0;i<100;i++)
    {
    }
    return glb(rev,n,x,y);
}
    
