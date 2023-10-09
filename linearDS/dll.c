#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data ; 
	struct node * prev;
	struct node * next;
}nod;

void create(nod**,int);
void traverse(nod *);
void insertHead(nod** , int);
void insertTail(nod** , int);
void insertAtPosition(nod** , int , int);
void deleteHead(nod **);
void deleteTail(nod **);
void deleteAtPosition(nod **,int);
int main(){
	nod *head = NULL ;
	create(&head , 5);
	insertHead(&head,0);
	insertTail(&head,6);
	insertAtPosition(&head,7,8);
	deleteHead(&head);
	deleteTail(&head);
	deleteAtPosition(&head , 2);
	traverse(head);
	return 0;
}
void create(nod **head, int n){
	if((*head) != NULL){
		printf("LIST CREATED\n");
		return;
	}
	int i , item ; 
	nod *newnode , *temp ; 
	for(i=1;i<=n;i++){
		printf("Enter node = ");	
		scanf("%d",&item);
		newnode = (nod*)malloc(sizeof(nod));
		newnode->data = item;
		newnode->next = NULL;
		if(*head == NULL){
			*head = newnode;
			newnode->prev = NULL;
		}
		else{
			temp->next = newnode;
			newnode->prev = temp;
		}
		temp = newnode;
	}
	return;
}

void traverse(nod *head){
	if(head == NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *pre , *cur ; 
	pre = NULL;
	cur = head;
	while(cur!=NULL){
		printf("%d->",cur->data);
		pre = cur ;
		cur = cur->next;
	}
	printf("\n");
	cur = pre ; 
	while(cur!=NULL){
		printf("%d->",cur->data);
		cur = cur->prev;
	}
	printf("\n");
	return;
}

void insertHead(nod **head, int item){
	if(*head == NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	newnode->next = *head;
	newnode->prev = NULL;
	(*head)->prev = newnode;
	*head = newnode;
	return;
}

void insertTail(nod **head, int item){
	if(*head == NULL){
		printf("EMPTY LIST\n");
		return ; 
	}
	nod *temp = *head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	nod *newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	newnode->next = NULL;
	newnode->prev=temp;
	temp->next = newnode;
	return;
}

void insertAtPosition(nod **head , int item , int pos){
	if(*head == NULL){
		printf("EMPTY LIST\n");
		return;

	}
	int count = 0 , cur;
	nod *temp = (*head);
	while(temp!=NULL){
		count++;
		temp = temp->next;

	}
	if(pos>count+1 || pos<=0){
		printf("INVALID POSITION\n");
		return;
	}
	temp = (*head);
	cur = 1;
	while(cur < pos-1 && temp!=NULL){
		cur++;
		temp = temp->next;

	}
	nod *newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	if(pos == 1)
	{

		newnode->next = (*head);
		
		newnode->prev = NULL;
		(*head)->prev = newnode;
		(*head) = newnode;
	}
	else{

		newnode->next = temp->next;
		if(pos!=count+1)
			newnode->next->prev = newnode;
		newnode->prev = temp;
		temp->next = newnode;
	}
	return;
}
void deleteHead(nod **head){
	if((*head) == NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *temp = (*head);
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp->next = NULL ;
	free(temp);
	return; 
}
void deleteTail(nod **head){
	if(*head == NULL){
		printf("EMPTY LIST\n");
		return;
	}
	nod *temp = (*head);
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->prev->next = NULL ; 
	temp->prev = NULL;
	free(temp);

	return;
}
void deleteAtPosition(nod **head , int pos){
	if(*head == NULL){
		printf("EMPTY LIST\n");
		return ;
	}
	int count = 1;
	nod *temp = (*head);
	while(temp != NULL && count!=pos){
		count++;
		temp = temp->next;
	} 
	
	if(pos<1 || pos>count || temp == NULL){
		printf("INVALID POSITION \n");
		return;
	}
	if(pos==1){
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
		return;
	}
	temp->prev->next = temp->next;
	if(temp->next!=NULL)
		temp->next->prev = temp->prev;
	temp->next = temp->prev = NULL;
	free(temp);
	return ;
}

