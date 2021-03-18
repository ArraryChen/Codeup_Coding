#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10010;

char pre[maxn], in[maxn];

struct node{
	
	char data;
	node *lchild, *rchild;

};

node* create(int preL, int preR, int inL, int inR){

	if ( preL > preR )
	{
		return NULL;
	}

	node* root = new node;
	root->data = pre[preL];

	int k;

	//�ҵ������
	for (k = inL; k <= inR; k++)
	{
		if ( in[k] == pre[preL] )
		{
			break;
		}
	}

	//�����������
	int numLeft = k - inL;

	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

	return root;
}

//�������
void postOrder(node* root){
	
	if ( root == NULL )
	{
		return;
	}

	if(root->lchild) postOrder(root->lchild);
	if(root->rchild) postOrder(root->rchild);

	printf("%c", root->data);
}

int main(){

	//��������, �������
	while ( scanf("%s %s", pre, in) != EOF )
	{
		//����
		int L1 = strlen(pre), L2 = strlen(in);

		//�����
		node* head = create(0, L1 - 1, 0, L2 - 1);

		//�������
		postOrder(head);

		printf("\n");
	}

	system("pause");
	return 0;
}
