#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

} nod;

void createNode(nod **head, int n)
{
	if((*head) != NULL)
	{
		printf("List is already created\n");
		return ; 
	}
	nod *newnode, *temp;
	int item, i;
	for (i = 1; i <= n; i++)
	{
		printf("Enter node = ");
		scanf("%d", &item);
		newnode = (nod *)malloc(sizeof(nod));
		newnode->data = item;
		newnode->next = NULL;
		if ((*head) == NULL)
			(*head) = newnode;
		else
			temp->next = newnode;
		temp = newnode;
	}
	return;
}


void traverse(nod *head)
{

	nod *temp = head;
	while (temp != NULL)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

void insertAtHead(nod **head , int item){
	if((*head) == NULL){
		printf("Empty list \n");
		return ;
	}

	nod *temp = (*head);
	nod *newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	newnode->next=temp;
	*head = newnode ; 
	
	return ;
}

void insertAtTail(nod **head , int item)
{
	if((*head == NULL)){
		printf("Empty List \n");
		return ;
	}
	
	nod *newnode = (nod*)malloc(sizeof(nod));
	newnode->data = item;
	newnode->next = NULL ; 
	nod *temp  =  (*head);
	while(temp->next != NULL){
		temp = temp->next;

	}
	temp->next = newnode ; 

	return;

}

void insertAtPosition(nod **head , int pos , int item){
	if(*head == NULL){
		printf("Empty List \n");
		return ; 
	}
	
	nod *newnode , *temp ;
	newnode = (nod*)malloc(sizeof(nod*)); 
	newnode->data = item;
	temp = (*head);

	int listLength = 0;
	while(temp!=NULL){
		listLength++;
		temp = temp->next;
	}
	//printf("%d\n",listLength);

	if(pos<=0 && pos>listLength+1){
		printf("INVALID POSITION \n");
		return;

	}

	temp = *head;
	nod *preTemp = NULL;
	int flag = 1 ; 
	if(pos == 1){
		newnode->next = temp;
		*head = newnode;
		return;

	}else{
		while(flag<pos-1 && temp!=NULL){
			
			temp = temp->next;
			flag++;

		}


	}
	newnode->next = temp->next;
	temp->next = newnode;
	//printf("%d %d" , temp->data , flag);
	return;

}

void deleteHead(nod **head){
	if((*head) == NULL){
		printf("EMPTY LIST \n");
		return;
	}
	nod *temp = *head ; 
	*head = (*head)->next;
	temp->next = NULL;
	free(temp);
	return;

}


void deleteTail(nod **head){
	if(*head==NULL){
		printf("EMPTY LIST\n");
		return;
	}

	nod *preTemp , *temp ; 
	preTemp = NULL;
	temp = *head;
	while(temp->next != NULL)
	{
		preTemp = temp ; 
		temp=temp->next;
	}
	preTemp->next = NULL ; 
	free(temp);
	return;
}

void deleteValue(nod **head, int val){

	if(*head == NULL){
		printf("EMPTY LIST\n");
		return;
	}

	nod *preTemp , *temp ; 
	preTemp = NULL; 
	temp = (*head);
	
	while(temp->data!= val){
		preTemp = temp;
		temp =temp->next;
		
	}

	if(temp==NULL){
		printf("NODE ABSENT");
		return;
	}else{
		preTemp->next = temp->next ; 
		temp->next = NULL; 
		free(temp);
	}
 
	return;
	

}

void reverseIterative(nod **head){
	if((*head) == NULL || (*head)->next ==NULL){
		printf("INVALID COMMAND \n");
		return;

	}
	
	nod *pre, *cur, *nex ; 
	pre = NULL ; 
	cur = (*head);
	
	while(cur != NULL){
		nex = cur->next ;  
		cur->next = pre ; 
		pre = cur ; 
		cur = nex ; 
	}
	*head = pre ; 
	return;


}

nod *reverseRecursive(nod *head){

	if(head == NULL || head->next ==NULL )
			return head;

	nod *newnode = reverseRecursive(head->next);
	head->next->next = head ; 
	head->next = NULL ; 
	return newnode;
}
int main()
{
	nod *head = NULL;
	createNode(&head, 5);
	insertAtHead(&head , 0);
	insertAtTail(&head , 6);
	insertAtPosition(&head , 3 , 7);
	traverse(head);
	deleteHead(&head);
	deleteTail(&head);
	deleteValue(&head , 7);
	reverseIterative(&head);
	traverse(head);
	
	nod *temp = reverseRecursive(head);
	traverse(temp);
	printf("%d", head->data);
	return 0;
}