/**
 * To use this file include (#include "LinkedList.cpp") it to other file
 * where you want to use linked list or
 * add #include <iostream> and main() function
 * on this file.
 */

typedef struct node node;

class LinkedList {
  int numberOfNode = 0;
  struct node {
    int data;
    node *next;
  };

  node *loc;  //, *prevNode ;
 public:
  node *head = NULL;
  LinkedList() {}

  void push(int data);
  void pop();
  void print();
  void remove(int data);
};

void LinkedList ::push(int data) {
  node *newNode = new node;
  newNode->data = data;
  newNode->next = NULL;

  if (numberOfNode == 0) {
    head = newNode;
    loc = head;
    // prevNode = head ;
  } else {
    loc->next = newNode;
    //   prevNode = loc ;
    loc = loc->next;
  }
  numberOfNode++;
  return;
}
void LinkedList ::pop() {
  if (!numberOfNode) {
    printf("no node to delete\n");
    return;
  }
  // create local loc
  node *currentNode = head;
  node *prevNode = head;
  while (currentNode->next) {
    prevNode = currentNode;
    currentNode = currentNode->next;
  }

  printf("deleted : %d\n", currentNode->data);
  prevNode->next = NULL;
  loc = prevNode;
  delete currentNode;
  numberOfNode--;
}
void LinkedList ::print() {
  node *currentNode = head;
  while (currentNode) {
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }
  printf("\n");
}
void LinkedList ::remove(int data) {
  node *currentNode = head;
  node *prevNode = head;
  int count = 0;
  while (currentNode) {
    if (currentNode->data == data) {
      // last node ? call pop()
      if (currentNode->next == NULL) {
        pop();
        return;
      }

      // first node point head to second node
      if (!count)
        head = currentNode->next;
      else  // other node? point previous node's next to next node
        prevNode->next = currentNode->next;

      numberOfNode--;
      printf("deleted : %d\n", currentNode->data);
      delete currentNode;
      return;
    }
    count++;
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
}