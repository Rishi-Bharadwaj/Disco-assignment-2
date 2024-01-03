#include<stdio.h>
#include<stdlib.h>

int havel(int n, int *a)
{
    while(1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[j-1]<a[j])
                {
                    int temp= a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                }
            }
        }

        if(a[0]==0)
        {
            return 1;
        }

        int d=a[0];
        a[0]=0;

        if(d>n-1)
        return 0;

        for(int i=1;i<n;i++)
        {
            a[i]=a[i]-1;
            if(a[i]<0)
            {
                return 0;
            }
        }
        int zeroes=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                for(int j=i;j<n-1;j++)
                {
                    a[j]=a[j+1];
                }
                zeroes++;
            }
        }
        n=n-zeroes;
    }
}

void main()
{
    int n;
    scanf("%d",&n);
    int *a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    havel(n,a)?printf("YES"):printf("NO");
    free(a);
}