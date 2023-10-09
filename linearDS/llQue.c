#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next; 
}que;

void enque(que **, que** , int);
void deque(que**,que**);
void peak(que*);
int main(){
	que *front = NULL, *rear = NULL ;
	enque(&front , &rear , 1);
	enque(&front , &rear , 2);
	enque(&front , &rear , 3);
	peak(front);
	deque(&front , &rear);
	peak(front);
	return 0;
}

void enque(que **front , que **rear , int n){
	que *newnode = (que*)malloc(sizeof(que));
	newnode->data = n;
	newnode->next = NULL; 
	if(*front == NULL){
		*front = newnode;
		*rear = newnode;

	}else{
		(*rear)->next = newnode;
		*rear = newnode;

	}
	return;
}
void deque(que **front , que **rear){
	if(*front == NULL)
	{
		printf("UNDERFLOW\n");
		return;
	}
	que *temp = *front;
	(*front) = temp->next;
	temp->next = NULL ;
	if(*front == *rear){
		*front = *rear = NULL;
	}
	free(temp);
	return;
}
void peak(que *front){
	printf("%d\n",front->data);

}