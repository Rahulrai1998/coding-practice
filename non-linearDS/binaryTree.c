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
nod* search_recursive(nod*,int);
nod* search_iterative(nod*,int);

void insert(nod*,int);

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


	//printf("%d\n",search_recursive(p,1)->data);
	insert(p,16);
	inorder(p);
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
	
nod *search_recursive(nod *root,int key){
	if(root==NULL) return NULL;
	if(key == root->data) return root;
	else if(key < root->data) return search_recursive(root->left,key);
	else return search_recursive(root->right,key);
}

nod *search_iterative(nod *root , int key){
	while(root!=NULL){
		if(root->data == key) return root;
		else if(root->data < key) root = root->left;
		else root= root->right;
	}
	return NULL;
}

void insert(nod *root , int key){
	nod *pre , *newnode ; 
	while(root!=NULL){
		pre = root;
		if(root->data == key) return;
		else if(key < root->data) root = root->left;
		else root = root->right;
	}
	newnode = createNode(16);
	
	if(pre->data < key) pre->right = newnode;
	else pre->left = newnode;
	return;
}
	