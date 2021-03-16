#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

struct node{

	int data;
	node *next;

};

//��ע,���ڴ���˵��������ǵ������������
//�������ϵĴ𰸶��Ǻ��Ե�������һ��,�����ڲ��������������������,���˴𰸿���ͨ��
//��ȷ������Ӧ���Ǳ߲��������,�����ظ�Ԫ�ز�����

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
