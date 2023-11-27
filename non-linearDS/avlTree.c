#include<stdio.h>
#include<stdlib.h>

typedef struct  node{
	int data;
	struct node *left;
	struct node *right;
	int height;
}nod;

int height(nod *root){
	if(root==NULL) return 0;
	else return root->height;
}
int max(int a , int b){
	return a>b ? a : b;

}
nod *create(int data){
	nod *node = (nod*)malloc(sizeof(nod));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

int getBalancedFactor(nod *n){
	if(n==NULL) return 0;
	else return height(n->left) - height(n->right);
}

nod *rotateRight(nod *y){
	nod *x = y->left;
	nod *T2 = x->right;

	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->right),height(y->left))+1;
	x->height = max(height(x->right),height(x->left))+1;
	
	return x;
}

nod *rotateLeft(nod *x){
	nod *y = x->right;
	nod *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->right),height(x->left))+1;
	y->height = max(height(y->right),height(y->left))+1;

	return y;
}

nod *insert(nod *root , int key){
	if(root==NULL)
		return create(key);
	if(key<root->data)
		root->left = insert(root->left,key);
	else if(key>root->data)
		root->right = insert(root->right,key);
	

	root->height = 1 + max(height(root->left),height(root->left));
	int bf = getBalancedFactor(root);

	//LL
	if(bf>1 && key < root->left->data)
		return rotateRight(root);
	//RR	
	if(bf<1 && key > root->right->data)
		return rotateLeft(root);

	//RL
	if(bf<1 && key<root->right->data)
	{
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}
	//LR
	if(bf>1 && key>root->left->data)
	{
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}
	return root;


}
int main(){
	nod *root = NULL;
	root = insert(root,1);
	root = insert(root,2);
	root = insert(root,4);
	root = insert(root,5);
	root = insert(root,6);
	root = insert(root,3);

	return 0;
}