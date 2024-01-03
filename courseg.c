#include<stdio.h>

typedef struct{
    int u;
    int v;
}edge;

int check(edge courses[],int ecount,int n,int * success,int * order,int ocount)
{
    int r=0;
    while(r<=n)
    {
        for(int i=1;i<=n;i++)
        {
            int flag=1;
            for(int j=0;j<ecount;j++)
            {
                if(courses[j].v==i && success[courses[j].u]!=1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1 &&success[i]!=1)
            {
                success[i]=1;
                order[ocount++]=i;
            }
        }
        r++;
    }

    int flag2=1;
    for(int i=1;i<=n;i++)
    {
        if(success[i]!=1)
        flag2=0;
    }
    return flag2;
}

void main()
{
    int n;
    scanf("%d",&n);
    edge courses[100];
    for(int i=0;i<100;i++)
    {
        courses[i].u=0;
        courses[i].v=0;
    }
    int ecount=0, success[n+1], order[n];
    
    for(int i=0;i<n;i++)
    {
        success[i]=0;
        order[i]=0;
    }
    success[n]=0;

    int z=0,w=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&z);
        for(int j=0;j<z;j++)
        {
            scanf("%d",&w);
            courses[ecount].u=w;
            courses[ecount++].v=i;
        }
    }
    
    if(check(courses,ecount,n,success,order,0))
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",order[i]);
        }
    }
    else printf("%d",-1);
}