#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int data , pr ; 
	struct queue *next ; 

}que;
void insert(que **head , int item , int p){
	que *temp = *head , *pre = NULL;
	while(temp!=NULL && temp->pr < p){
		pre = temp;
		temp = temp->next;

	}
	que *newnode = (que*)malloc(sizeof(que));
	newnode->data = item;
	newnode->pr = p;
	if(temp == (*head)){
		newnode->next = (*head);
		*head = newnode;
	}
	else{
		newnode->next = pre->next;
		pre->next = newnode;
	}
	return;
}
void traverse(que *head){
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->next;

	}


}
void delete(que **head){
		
	que *temp = (*head);
	(*head) = (*head)->next;
	temp->next = NULL;
	free(temp);

	return;
}
int main(){
	que *head = NULL;
	insert(&head , 1 , 1);
	insert(&head , 2 , 2);
	insert(&head , 3 , 3);
	insert(&head , 4 , 2);
	delete(&head);
	traverse(head);
	return 0;
}