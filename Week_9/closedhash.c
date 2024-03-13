#include<stdio.h>
#include<stdlib.h>
#define size 11
int count;

struct node{
  int data;
  struct node *next;
};

struct node *chain[size];

void init(){
  int i;
  count=0;
  for(i = 0; i < size; i++)
    chain[i] = NULL;
}

void insert(int value){
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = value;
  newNode->next = NULL;
  int key = value % size;
    
  if(chain[key] == NULL){
    chain[key] = newNode;
    count++;
  }
    
  else{
    struct node *temp = chain[key];
    while(chain[key]!=NULL){
      key++;
      count++;
      key=key%size;
    }
    chain[key]= newNode;
    count++;
  }
}

void print(){
  int i;
  for(i = 0; i < size; i++){
    struct node *temp = chain[i]; 
    printf("chain[%d]-->",i);
    if (temp) printf("%d\n",chain[i]->data);
    else printf("NULL\n");
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