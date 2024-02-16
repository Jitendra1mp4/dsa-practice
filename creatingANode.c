#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node {
  int data;
  Node *link;
};

int main(int argc, char const *argv[]) {
  Node *head = NULL;
  Node *current = (Node *)malloc(sizeof(Node));
  current->data = 5 ;
  current->link = NULL ;
  head = current ;

  printf("data of node1 : %d\n",head->data) ;

  current = (Node *)malloc(sizeof(Node)) ;
  current->data = 6 ;
  current->link = NULL ;

  head->link = current ;
  printf("data of node2 : %d\n",head->link->data);


  current = (Node *) malloc(sizeof(Node)) ;
  current->data = 12 ;
  current->link = NULL ;
  head->link->link = current ;
  printf("data of node3 : %d\n",head->link->link->data);

  return 0;
}
