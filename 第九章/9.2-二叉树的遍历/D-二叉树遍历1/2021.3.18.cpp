#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

struct node{

	char data;
	node* lchild;
	node* rchild;

};

char str[110];

node* create(node* root, int &pos){

	pos++;
	if ( str[pos] == '#' )
	{
		root = NULL;
		return root;
	}

	root = new node;
	root->data = str[pos];

	root->lchild = create(root->lchild, pos);
	root->rchild = create(root->rchild, pos);

	return root;
}

void inOrder(node* root){

	if ( root == NULL ) return;

	inOrder(root->lchild);
	printf("%c ", root->data);
	inOrder(root->rchild);

}

int main(){

	while ( scanf("%s", str) != EOF )
	{
		int pos = -1;

		node* head = NULL;
		head = create(head, pos);

		inOrder(head);

		printf("\n");
	}

	system("pause");
	return 0;
}
