#include<stdio.h>
int n;
int adj[10][10];
int i,j;
int visited[10];

int pushtop=-1;
int poptop=-1;

int pushstack[10];
int poparr[10];

void push(int pushstack[],int vertex)
{
	pushstack[++pushtop]=vertex;
}

void pop(int pushstack[],int poparr[])
{
	poparr[++poptop]=pushstack[pushtop--];
}

void dfs(int n){
	int vertex=pushstack[pushtop];
	for(int i=0;i<n;i++)
	{
		if(adj[vertex][i]==1)
		{
			if(!visited[i])
			{
				visited[i]=1;
				printf(" %d",i);
				push(pushstack,i);
				dfs(n);

			}
		}
	}
	pop(pushstack,poparr);
}

int main(){
	printf("Enter the number of vertices of DAG:  ");
	scanf("%d", &n);
	for (i = 0; i <n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter graph data in matrix form:    \n");
    for (i = 0; i < n; i++)
        for (j = 0; j <n; j++)
            scanf("%d", &adj[i][j]);

    printf("output: ");
	for(int i=0;i<n;i++)
      if(!visited[i]){
        printf(" %d",i);
        visited[i]=1;
        push(pushstack,i);
        dfs(n);
      }

	printf("\npoporder:");
	for(int i=0;i<=poptop;i++)
		printf(" %d",poparr[i]);
	printf("\n");

	printf("\nTopological Sort order:");
	for(int i=poptop;i>=0;i--)
		printf(" %d",poparr[i]);
	printf("\n");
}