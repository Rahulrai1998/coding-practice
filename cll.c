#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}nod;
void create(nod**, int);
void traverse(nod*);
void insertAtHead(nod** , int);
void insertAtTail(nod** , int);
void deleteHead(nod**);
void deleteTail(nod**);
void insertion(nod**,int,int);
void deletion(nod**,int);
int main(){
	nod *head = NULL;
	create(&head , 5);
	insertAtHead(&head , 0);
	insertAtTail(&head , 6);
	traverse(head);
	deleteHead(&head);
	deleteTail(&head);
	traverse(head);
	reverse(&head);
	traverse(head);
	return 0;
}
void create(nod **head , int n){
	if(*head != NULL){
		printf("LIST CREATED\n");
		return;
	}
	nod *newnode , *temp ; 
	int i , item;
	for(i=1;i<=n;i++){
		printf("Enter node = ");
		scanf("%d",&item);
		newnode = (nod*)malloc(sizeof(nod));
		newnode->data = item;
		if(*head == NULL){
			*head = newnode;

		}else{
			temp->next = newnode;
			
		}
		temp = newnode;
		
	}
	newnode->next = *head;
	return;
}
void traverse(nod* head){
	if(head== NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *temp = head;
	do{
		printf("%d->",temp->data);
		temp = temp->next;

	}while(temp!=head);
	return;
}
void insertAtHead(nod **head , int item){
	if(*head == NULL){
		printf("EMPTY LIST\n");
		return;

	}
	nod *newnode , *temp;
	temp = (*head);
	while(temp->next!= *head){
		temp = temp->next;
		
	}
	newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	temp->next = newnode;
	newnode->next = (*head);
	*head = newnode;
	return;
}
void insertAtTail(nod **head , int item){
	if((*head)==NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *newnode , *temp = (*head);
	while(temp->next!=*head){
		temp = temp->next;
	}
	newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	temp->next = newnode;
	newnode->next = (*head);
	return;
}
void deleteHead(nod **head){
	if((*head)==NULL){
		printf("EMPTY LIST\n");
		return;
	}
	
	nod *temp , *pre ; 
	temp = (*head);
	pre = NULL;
	do{
		pre = temp;
		temp = temp->next;

	}while(temp!=(*head));
	
	(*head) = (*head)->next;
	temp->next = NULL;
	pre->next = *head;
	free(temp);
	return;
}
void deleteTail(nod **head){
	if(*head == NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *temp, *pre;
	temp = *head;
	pre = NULL;
	while(temp->next!=*head){
		pre = temp;
		temp = temp->next;
	}
	temp->next=NULL;
	pre->next = *head;
	free(temp);
	return;
}
void insertion(nod **head , int pos , int item){
	if((*head)==NULL){
		printf("EMPTY LIST\n");
		return;
	}
	int count = 0 ; 
	nod *temp = (*head) , *newnode;
	do{
		count++;
		temp=temp->next;
	}while(temp!=(*head));
	if(pos<=0 || pos>count+1)
	{
		printf("INVALID POSITION\n");
		return;
	}
	temp = (*head);
	int cur = 1 ;
	newnode=(nod*)malloc(sizeof(nod));
	newnode->data = item ; 
	while(cur!=pos-1){
		temp=temp->next;
		cur++;
	}
	if(pos == 1){
		newnode->next = (*head);
		*head = newnode;
		nod *temp2 = (*head);
		while(temp->next!=*head);
		{
			temp= temp->next;
		}
		temp->next=newnode;
		*head = newnode;
	}else{
		newnode->next = (*head);
		temp->next = newnode;
	}
	return;
}
void deletion(nod **head , int pos){
	if((*head)==NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *cur , *prev ; 
	cur = (*head);
	prev = NULL;
	int count = 0 ;
	do{
		cur = cur->next;
		count++;
	}while(cur!=(*head));
	if(pos<=0 || pos>count){
		printf("INVALID POSITION\n");
		return;
	}
	cur = (*head);
	int n = 1;
	while(n!=pos){
		prev = cur;	
		cur = cur->next;
		n++;
	}
	prev->next = cur->next;
	cur->next = NULL;
	free(cur);
	return;
}
void reverse(nod **head){

	if(*head == NULL || (*head)->next == NULL){
		printf("EITHER EMPTY LIST OR SINGLE NODE\n");
		return;
	}
	nod *cur , *pre , *nxt ; 
	cur = (*head);
	pre = NULL ;
	nxt = NULL ;
	do{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}while(cur!=(*head));
	(*head)->next = pre;
	(*head) = pre;
	return;
}