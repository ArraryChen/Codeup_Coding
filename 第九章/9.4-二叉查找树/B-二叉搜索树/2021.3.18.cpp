#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

vector<int> temp;	//保存待检测的二叉排序树的先序序列
vector<int> ans;	//保存已给的二叉排序树的先序序列

struct node{

	int data;
	node* lchild;
	node* rchild;

};

//构建二叉排序树
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

//先序遍历
void preOrder(node* root){

	if ( root == NULL ) return;
	
	temp.push_back(root->data);
	if (root->lchild) preOrder(root->lchild);
	if (root->rchild) preOrder(root->rchild);
}

//比较两棵二叉排序树的先序序列
bool comTwo(vector<int> v1, vector<int> v2){

	for (int i = 0; i < v1.size(); i++)
	{
		if ( v1[i] != v2[i] )
		{
			return false;
		}
	}
	return true;
}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		//先构建已知的二叉排序树
		char input[20];
		scanf("%s", input);

		node* head = NULL;
		int length = strlen(input);

		for (int i = 0; i < length; i++)
		{
			head = create(head, input[i] - '0');
		}

		//并把其先序序列保存在ans中
		preOrder(head);

		ans = temp;
		temp.clear();
		
		//再构建待检查的二叉排序树,同时保存其先序序列进temp
		for (int i = 0; i < n; i++)
		{
			scanf("%s", input);

			node* p = NULL;
			int length1 = strlen(input);

			for (int j = 0; j < length1; j++)
			{
				p = create(p, input[j] - '0');
			}

			preOrder(p);

			//若两者相同,其先序序列相等
			if ( comTwo(temp, ans) ) printf("YES\n");
			else printf("NO\n");

			temp.clear();
		}

		temp.clear();
		ans.clear();
	}

	system("pause");
	return 0;
}
