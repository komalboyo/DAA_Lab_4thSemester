#include<stdio.h>
#include <stdbool.h>
void bubble_sort(int* arr, int n){
	int Opcount=0;
	for (int i=0;i<n-1;i++){
		//bool flag=false;
		for (int j=0;j<n-i-1;j++){
			Opcount++;
			if (arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				//flag=true;
				//Opcount++;
			}
		}
		//if(!flag) return;
	}
	printf("%d\n", Opcount);
}
int main (){
	int arr[]={1,4,10,1,7,2,3,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, n);
	for (int i=0;i<n;i++){
		printf("%d  ", arr[i]);
	}
}