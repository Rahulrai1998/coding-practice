#include<stdio.h>
#include<stdlib.h>
#define MAX 100 

typedef struct queue{
	int front , rear;
	int arr[MAX];

}que;

int empty(que*);
int full(que*);
int peak(que*);
void enque(que*,int);
void deque(que*);

int main(){
	que q ; 
	que *p = &q;
	p->front = p->rear = -1 ; 
	
	enque(p , 1);
	enque(p , 2);
	enque(p , 3);
	enque(p , 4);
	printf("%d\n",peak(p));
	deque(p);
	printf("%d\n",peak(p));
	deque(p);
	printf("%d\n",peak(p));

	return 0;
}

int empty(que*p){
	return (p->front == -1 && p->rear == -1);

}
int full(que*p){
	return (p->front > p->rear) || (p->front == 0 && p->rear == MAX-1); 
}
int peak(que*p){
	return p->arr[p->front];
}
void enque(que*p , int item){
	if(full(p)){
		printf("OVERFLOW\n");
		return;
	}
	if(p->front == -1) {
		p->front = p->rear = 0;
	}
	else if(p->rear == MAX-1){ p->rear = 0 ;}
	else p->rear++ ; 

	p->arr[p->rear] = item; 
	return;
}
void deque(que *p){
	if(empty(p)){
		printf("UNDERFLOW\n");
		return;
	}
	
	if(p->rear == p->front){
		p->rear = p->front = -1;
	}else if(p->front == MAX-1){
		p->front = 0;
	}else{
		p->front++;
	}
	return;
}

