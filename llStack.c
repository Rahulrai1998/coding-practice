#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}nod;

int isEmpty(nod*);
int top(nod*);
void pop(nod**);
void push(nod** , int);
int main(){
	nod *tp  = NULL ;
	push(&tp , 1);
	push(&tp , 2);
	push(&tp , 3);
	top(tp);
	pop(&tp);
	top(tp);	
	return 0;
}
int isEmpty(nod *top){
	return top == NULL;
}
int top(nod *tp){
	if(isEmpty(tp)) {
		printf("EMPTY STACK\n");
		return -99999;
	} 
	printf("%d\n",tp->data);
	return 1;
}
void push(nod **top , int item){
	nod *newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	newnode->next = *top;
	(*top) = newnode;
	return;
}
void pop(nod **top){
	if(isEmpty(*top)){
		printf("EMPTY STACK\n");
		return;

	}
	nod *temp = *top;
	*top = (*top)->next;
	temp->next = NULL;
	free(temp);
	return;
}
