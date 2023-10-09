#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}nod;

nod *createNode(int);
void inorder(nod*);
void preorder(nod*);
void postorder(nod*);

int isBST(nod*);

int main(){
	
	nod *p = createNode(5);
	nod *p1 = createNode(3);
	nod *p2 = createNode(6);
	nod *p3 = createNode(1);
	nod *p4 = createNode(4);
	

	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;
	

	//preorder(p);
	//printf("\n");
	//inorder(p);
	//printf("\n");
	//postorder(p);


	printf("%d\n",isBST(p));

	return 0;
}
nod *createNode(int data){
	nod *newnode = (nod*)malloc(sizeof(nod));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void preorder(nod *root){
	if(root != NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
		
	}
	return;
}
void postorder(nod *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
	return;
}
void inorder(nod *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
	return;
}

int isBST(nod *root){
	static nod *prev = NULL;
	if(root!=NULL){
		if(!isBST(root->left)) return 0;
		if(prev!=NULL && root->data <= prev->data) return 0;
		prev = root;
		return isBST(root->right);
	}
	else return 1;
}
	
	