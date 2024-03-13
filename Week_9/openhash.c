#include<stdio.h>
#include<stdlib.h>
#define size 5
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
    int i=1;
    struct node *temp = chain[key];
    while(temp->next){
      temp = temp->next;
      i++;
    }
    temp->next = newNode;
    i++;
    count+=i;
  }
}

void print(){
  int i;
  for(i = 0; i < size; i++){
    struct node *temp = chain[i]; 
    printf("chain[%d]-->",i);
    while(temp){
      printf("%d -->",temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
  printf("The count: %d\n", count);
}

int main(){
  init();
  insert(7);
  insert(0);
  insert(3);
  insert(10);
  insert(4);
  insert(5);
  print();
  printf("\n");
  init();
  insert(8);
  insert(3);
  insert(9);
  insert(4);
  insert(7);
  insert(0);
  //insert(11);
  insert(5);
  insert(1);
  insert(2);
  print();
  return 0;
}