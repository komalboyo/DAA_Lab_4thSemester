#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 999

int min(int a,int b)
{
    return a<b?a:b;
}

void Floyd(int** M,int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                M[i][j] = min( M[i][j], M[i][k] + M[k][j] );
}

void main()
{
    int n;
    printf("Enter No. of Vertices :  ");
    scanf("%d",&n);
    int** adj=(int **)calloc(n,sizeof(int *));
    printf("\nEnter Weighted Adjacency Matrix (Enter -1 for Infinity): \n");
    for(int i=0;i<n;i++)
    {
        adj[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==-1)
            {
                adj[i][j]=MAX;
            }
        }
    }
    Floyd(adj,n);
    printf("\nAll Pairs Shortest Path Matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}