#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct stk{
	int arr[MAX];
	int top;
}stack;

int isEmpty(stack*);
int isFull(stack*);
void push(stack* , int);
void pop(stack*);
int top(stack*);

int main(){
	stack st; 
	stack *stp = &st;
	stp->top = -1;
	
	push(stp , 1);
	push(stp , 2);
	push(stp , 3);
	printf("%d\n",top(stp));
	pop(stp);
	printf("%d\n",top(stp));
	return 0;
}

int isEmpty(stack *stp){
	if(stp->top == (-1)) return 1;
	else return 0;
}
int isFull(stack *stp){
	if(stp->top == MAX-1) return 1;
	else return 0;
}
int top(stack *stp){
	if(isEmpty(stp)){
		printf("UNDERFLOW\n");
		return -99999;
	}
	return stp->arr[stp->top];
}
void push(stack *stp ,int item){
	if(isFull(stp)){
		printf("OVERFLOW\n");
		return;
	}
	stp->top++;
	stp->arr[stp->top] = item;
	return;
}
void pop(stack *stk){
	if(isEmpty(stk)){
		printf("UNDERFLOW\n");
		return;
	}
	stk->top--;
	return;
}


 
