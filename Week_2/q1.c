#include<stdio.h>

unsigned int GCDinntegerchck(int m,int n){
	int op = 0;
	int x = m < n ? m : n;
	int i;
	for(i=x;i>0;i--){
		//decrement is the basic operation
		op++;
		if(m%i == 0 && n%i == 0){
			break;
		}
	}
	printf("Operation count is %d\n",op);
	return i;
}

int main(){
	int a,b;
	printf("Enter the two integers : ");
	scanf("%d %d",&a,&b);
	int gcd = GCDinntegerchck(a,b);
	printf("GCD of the two integers is %d\n",gcd);
}                                                              
