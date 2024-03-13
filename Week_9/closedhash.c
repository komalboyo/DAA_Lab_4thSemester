#include<stdio.h>
#include<stdlib.h>
#define size 11
#define nan -9999
int count;

int arr[size];

void init(){
  count=0;
  for(int i = 0; i < size; i++)
    arr[i] = nan;
}

void insert(int value){
  int key = value % size;
  if(arr[key] == nan){
    arr[key] = value;
    count++;
  }
    
  else{
    while(arr[key]!=nan){
      key++;
      count++;
      key=key%size;
    }
    arr[key]= value;
    count++;
  }
}

void print(){
  for(int i = 0; i < size; i++){
    printf("A[%d]-->",i);
    if (arr[i]!=nan) printf("%d\n",arr[i]);
    else printf("nan\n");
  }
  printf("The count: %d\n", count);
}

int main(){
  init();
  insert(30);
  insert(20);
  insert(56);
  insert(75);
  insert(31);
  insert(19);
  print();
  return 0;
}
