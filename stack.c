#include <stdio.h>
#define n 5
int top = -1;

void push(int stack[], int data){
    if (top == n - 1){
        printf("overflowed!\n");
        return; // overflow
    }
    stack[++top] = data;
}
void pop(int stack[]){
    if (top == -1){
        printf("underflowed!\n");
        return; // underflow
    }

    printf("pop out : %d\n", stack[top--]);
}
void display(int stack[]){
    for (int i = top; i >= 0; i--)
        printf("%d ",stack[i]);
    printf("\n");
}

int main(){
    int stack[n];
	push(stack,5) ;
	push(stack,6) ;
	push(stack,7) ;
	push(stack,8) ;
	push(stack,8) ;
	push(stack,8) ;
	display(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	display(stack) ;
}
