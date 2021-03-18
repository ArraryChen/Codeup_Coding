#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 30;

struct node{

	char data;
	node* lchild;
	node* rchild;

};

char pre[maxn], in[maxn];

node* change(int preL, int preR, int inL, int inR){

	if ( preL > preR ) return NULL;

	node* root = new node;
	root->data = pre[preL];

	int k = inL;

	while ( pre[preL] != in[k] ) k++;

	int numberL = k - inL;

	root->lchild = change(preL + 1, preL + numberL, inL, k - 1);
	root->rchild = change(preL + numberL + 1, preR, k + 1, inR);

	return root;

}


void postOrder(node* root){

	if ( root == NULL ) return;

	if (root->lchild) postOrder(root->lchild);
	if (root->rchild) postOrder(root->rchild);

	printf("%c", root->data);

}

int main(){

	while ( scanf("%s %s", pre, in) != EOF )
	{

		int L1 = strlen(pre), L2 = strlen(in);

		node* head = change(0, L1 - 1, 0, L2 - 1);

		postOrder(head);

		printf("\n");
	}

	system("pause");
	return 0;
}
