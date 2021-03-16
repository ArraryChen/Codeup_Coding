#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

struct node{

	int data;
	node *next;

};

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 )
		{
			printf("list is empty\n");
			break;
		}

		node *head, *p;
		head = new node;
		head->next = NULL;

		vector<int> nums;

		for (int i = 0; i < n; i++)
		{
			int num;

			p = new node;
			scanf("%d", &num);

			nums.push_back(num);

			p->data = num;
			p->next = head->next;
			head->next = p;
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
