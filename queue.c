#include <stdio.h>
#define n 5
typedef enum { false, true } bool;
int front = -1, rear = -1;
bool isOverflow() {
  return ((front == 0 && rear == n - 1) || (front == rear + 1));
}

bool isUnderflow() { return front == -1; }

void enqueue(int queue[], int item) {
  // check if overflow
  if (isOverflow()) {
    printf("overflow\n");
    return;
  }

  // set value of rear
  if (front == -1) {
    front = rear = 0;
  } else if (rear == n - 1) {
    rear = 0;
  } else
    rear = rear + 1;

  // assign item
  queue[rear] = item;
}

void dequeue(int queue[]) {
  if (isUnderflow()) {
    printf("Underflow\n");
    return;
  }
  // process item
  printf("%d ", queue[front]);

  // update front
  if (front == rear)
    front = rear = -1;
  else if (front == n - 1)
    front = 0;
  else
    front = front + 1;
}

int main(int argc, char const *argv[]) {
  int queue[n];
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 14);
  enqueue(queue, 15);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  return 0;
}
