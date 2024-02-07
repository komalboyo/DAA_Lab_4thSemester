#include <stdio.h>
// N vertices and M Edges
int N, M;
typedef struct Node{
	int value;
	struct Node *lchild;
}Node;

typedef struct Node* Nodeptr;

void createAdjMatrix(int Adj[][N + 1],
                     int arr[][2])
{
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            Adj[i][j] = 0;
        }
    }
    // Traverse the array of Edges
    for (int i = 0; i < M; i++) {
        int x = arr[i][0];
        int y = arr[i][1];
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void printAdjMatrix(int Adj[][N + 1])
{
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    N = 5;
 
   	int arr[][2] = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 5 } };
    // Number of Edges
    M = sizeof(arr) / sizeof(arr[0]);
    // For Adjacency Matrix
    int Adj[N + 1][N + 1];
    createAdjMatrix(Adj, arr);
    printAdjMatrix(Adj);
    Nodeptr* adjlist[N];
    for (int i=0;i<N;i++){
    	adjlist[i]->value=i+1;
    	for (int k=1;k<N+1;k++){
    		if (Adj[i+1][k]==1){
    			Nodeptr node = (Nodeptr)malloc(sizeof(Node));
    			node->value = k;
    			node->lchild=NULL;
    			while()
    		}
    	}
    }
}
