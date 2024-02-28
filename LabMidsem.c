//Find Max and Min elements without sorting using divide and conquer

#include <stdio.h>

int FindMax(int arr[],int l,int r)
{
	if(l==r)
		return arr[l];
	int mid=l+(r-l)/2;
	int max_left=FindMax(arr,l,mid);
	int max_right=FindMax(arr,mid+1,r);
	return max_left>max_right? max_left : max_right;
}

int FindMin(int arr[],int l,int r)
{
	if(l==r)
		return arr[l];
	int mid=l+(r-l)/2;
	int min_left=FindMin(arr,l,mid);
	int min_right=FindMin(arr,mid+1,r);
	return min_left<min_right? min_left : min_right;
}

int main()
{
	printf("No. of elements? ");
	int n;
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int max=FindMax(arr,0,n-1);
	int min=FindMin(arr,0,n-1);
	printf("Maximum: %d\n",max);
	printf("Minimum: %d\n",min);
}
