#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct deque{
	int arr[SIZE];
	int right , left ; 

}deq;

int empty(deq*);
int full(deq*);
void insertLeft(deq* , int);
void deleteLeft(deq*);
void insertRight(deq* , int);
void deleteRight(deq*);
void leftRight(deq*);
int main(){
	deq dq;
	deq *d = &dq;
	d->left = d->right = -1 ;
	 
	insertLeft(d , 1);
	insertLeft(d,2);
	insertRight(d,0);
	leftRight(d);

	return 0;
}
int empty(deq* d){
	return (d->right == d->left == -1) ; 
}
int full(deq* d){
	return (d->left == 0 && d->right == SIZE - 1) || (d->left == d->right + 1);
}
void insertLeft(deq *d , int item){
	if(full(d)){
		printf("OVERFLOW\n");
		return;
	}	
	if(empty(d)){
		d->right = d->left = 0;

	}
	else if(d->left == 0){
		d->left = SIZE-1;
	}
	else{
		d->left = d->left-1;
	}
	d->arr[d->left] = item;
	return;
}
void deleteLeft(deq* d){
	if(empty(d)){
		printf("UNDERFLOW\n");
		return;
	}
	if(d->right == d->left){
		d->right = d->left = -1;
	}
	else if(d->left == SIZE-1){
		d->left = 0;
	}
	else{
		d->left = d->left + 1;
	}
	return;
}
void insertRight(deq *d , int item){
	if(full(d)){
		printf("OVERFLOW\n");
		return;
	}
	if(empty(d)){
		d->right = d->left = 0;
	}
	else if(d->right == SIZE-1){
		d->right = 0;
	}else{
		d->right = d->right + 1;
	}
	d->arr[d->right] = item; 
	return;
}
void deleteRight(deq *d){
	if(empty(d)){
		printf("UNDERFLOW\n");
		return;
	}
	
	if(d->right == d->left){
		d->right = d->left = -1;
	}
	else if(d->right == 0){
		d->right = SIZE-1;
	}
	else{
		d->right = d->right - 1 ;
	}
	return;
}
void leftRight(deq *d){
	printf("%d %d",d->arr[d->left] , d->arr[d->right]);
}
