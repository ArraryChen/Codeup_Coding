#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

struct node{

	int data, height;
	node *lchild, *rchild;

};

int getHeight(node* root){
	
	if (root == NULL) return 0;
	return root->height;

}

void updateHeight(node* root){
	
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;

}

int getBalanceFactor(node* root){

	return getHeight(root->lchild) - getHeight(root->rchild);

}

void L(node* &root){

	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(node* &root){

	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int n){

	if ( root == NULL )
	{
		root = new node;
		root->data = n;
		root->height = 1;
		root->lchild = root->rchild = NULL;

		return;
	}

	if ( n < root->data )
	{
		insert(root->lchild, n);

		updateHeight(root);

		if ( getBalanceFactor(root) == 2 )
		{
			if ( getBalanceFactor(root->lchild) == 1 )
			{
				R(root);
			}
			else if ( getBalanceFactor(root->lchild) == -1 )
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild, n);
		
		updateHeight(root);

		if ( getBalanceFactor(root) == -2 )
		{
			if ( getBalanceFactor(root->rchild) == -1 )
			{
				L(root);
			}
			else if ( getBalanceFactor(root->rchild) == 1 )
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}

node* create(int data[], int n){
	
	node* root = NULL;

	for (int i = 0; i < n; i++)
	{
		insert(root, data[i]);
	}

	return root;
}

void search(node* root, int x){

	if ( root == NULL )
	{
		printf("0");
		return;
	}

	if ( root->data == x )
	{
		printf("1");
	}
	else if ( x < root->data )
	{
		search(root->lchild, x);
	}
	else
	{
		search(root->rchild, x);
	}
}

int main(){

	int n, k;
	while ( scanf("%d %d", &n, &k) != EOF && n && k )
	{
		int data[510], s_num[510];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &data[i]);
		}

		node* head = create(data, n);
		
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &s_num[i]);
		
			search(head, s_num[i]);

			if ( i < k - 1 ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}
