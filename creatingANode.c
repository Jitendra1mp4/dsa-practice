#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node {
  int data;
  Node *next;
};

int main(int argc, char const *argv[]) {
  Node *head = NULL;
  head = (Node *)malloc(sizeof(Node));
  head->data = 5;
  head->next = NULL;
  printf("data : %d\n", head->data);
  return 0;
}
