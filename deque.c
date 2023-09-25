#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct deque{
	int arr[SIZE];
	int right , left ; 

}deq;

int empty(deq*);
int full(deq*);

int main(){
	deq dq;
	deq *d = &dq;
	d->left = d->right = -1 ;
	 

	return 0;
}
int empty(deq* d){
	return (d->right == d->left == -1) ; 
}
int full(deq* d){
	return (d->left == 0 && d->right == SIZE - 1) || (d->left == d->right + 1);
}