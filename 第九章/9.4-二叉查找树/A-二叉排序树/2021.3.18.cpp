#include<cstdio>
#include<iostream>

using namespace std;

struct node{

	int data;
	node* lchild;
	node* rchild;

};

node* create(node* root, int n){

	if ( root == NULL )
	{
		root = new node;
		root->data = n;
		root->lchild = root->rchild = NULL;
		return root;
	}

	if ( n > root->data ) root->rchild = create(root->rchild, n);
	else if ( n < root->data ) root->lchild = create(root->lchild, n);

	return root;
}

void preOrder(node* root){

	if ( root == NULL ) return;

	printf("%d ", root->data);
	if ( root->lchild ) preOrder( root->lchild );
	if ( root->rchild ) preOrder( root->rchild );
}

void inOrder(node* root){

	if ( root == NULL ) return;

	if ( root->lchild ) inOrder( root->lchild );
	printf("%d ", root->data);
	if ( root->rchild ) inOrder( root->rchild );
}

void postOrder(node* root){

	if ( root == NULL ) return;

	if ( root->lchild ) postOrder( root->lchild );
	if ( root->rchild ) postOrder( root->rchild );
	printf("%d ", root->data);
}

int main(){

	int n;

	while ( scanf("%d", &n) != EOF && n )
	{
		int N;
		node* head = NULL;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &N);
			head = create(head, N);
		}

		preOrder(head);
		printf("\n");

		inOrder(head);
		printf("\n");

		postOrder(head);
		printf("\n");
	}

	system("pause");
	return 0;
}
