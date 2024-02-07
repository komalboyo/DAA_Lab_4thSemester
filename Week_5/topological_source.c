#include<stdio.h>

int n;
int adj[10][10];
int i,j;
int visited[10];
int indegree[10];

void topological_source(){
	for (int i=0;i<n;i++){
		if (!visited[i]){
			if (indegree[i]==0){
				visited[i]=1;
				printf("%d  ", i);
				for (int j=0;j<n;j++){
					if (adj[i][j]==1){
						adj[i][j]=0;
						indegree[j]--;
					}
				}
				topological_source();
			}
		}
	}
}

int main(){
	printf("Enter the number of vertices of DAG:  ");
	scanf("%d", &n);
    printf("Enter graph data in matrix form:    \n");
    for (i = 0; i < n; i++){
    	visited[i]=0;
    	indegree[i]=0;
        for (j = 0; j <n; j++)
            scanf("%d", &adj[i][j]);
    }

    for(int j=0;j<n;j++){
    	for (int i=0;i<n;i++){
    		indegree[j]+=adj[i][j];
    	}
    }

    for (int i=0;i<n;i++){
    	printf("%d  ", indegree[i]);
    }

    printf("\nTopological Order: ");
    topological_source();
    for (int i=0;i<n;i++){
    	if (!visited[i]){
    		printf("%d  ", i);
    	}
    }
}