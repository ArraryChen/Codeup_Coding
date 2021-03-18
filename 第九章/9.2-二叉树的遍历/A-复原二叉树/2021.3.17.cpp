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

	//找到根结点
	for (k = inL; k <= inR; k++)
	{
		if ( in[k] == pre[preL] )
		{
			break;
		}
	}

	//左子树结点数
	int numLeft = k - inL;

	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

	return root;
}

//后序遍历
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

	//输入先序, 中序遍历
	while ( scanf("%s %s", pre, in) != EOF )
	{
		//长度
		int L1 = strlen(pre), L2 = strlen(in);

		//根结点
		node* head = create(0, L1 - 1, 0, L2 - 1);

		//后序遍历
		postOrder(head);

		printf("\n");
	}

	system("pause");
	return 0;
}
