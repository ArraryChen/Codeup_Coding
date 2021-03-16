#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

struct node{

	int data;
	node *next;

};

//备注,由于此题说明构造的是递增排序的链表
//但从网上的答案都是忽略的排序这一步,且由于测试用例都是有序输入的,到此答案可以通过
//正确的做法应该是边插入边排序,并且重复元素不插入

void insert(node *head, node *p){

	node *pre, *q;
	pre = head, q = head->next;

	while ( q && p->data > q->data )
	{
		pre = q;
		q = q->next;
	}

	if ( q )
	{
		if ( q->data == p->data ) return;
	}

	p->next = q;
	pre->next = p;
	return;
}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 )
		{
			printf("list is empty\n");
			continue;
		}

		int num;
		vector<int> nums;

		node *head, *p;
		head = new node;
		head->next = NULL;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);

			p = new node;
			p->data = num;
			
			nums.push_back(num);

			insert(head, p);
		}

		for (int i = 0; i < nums.size(); i++)
		{
			printf("%d", nums[i]);
			if ( i < nums.size() - 1 ) printf(" ");
			else printf("\n");
		}

		p = head->next;

		while ( p )
		{
			printf("%d", p->data);

			if ( p->next ) printf(" ");
			else printf("\n");

			p = p->next;
		}
	}

	system("pause");
	return 0;
}
