#include<stdio.h>

void insertion_sort(int arr[]){
	int n=7;
	int v,j;
	for(int i=1;i<=n-1;i++){
		v=arr[i];
		j=i-1;
		while (j>=0 && arr[j]>v){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=v;
	}
}

int main(){
	int arr[]={89,45,68,90,29,34,17};
	insertion_sort(arr);
	for (int i=0;i<7;i++){
		printf("%d  ", arr[i]);
	}
}