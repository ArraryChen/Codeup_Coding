#include<cstdio>
#include<iostream>

using namespace std;

struct Node{

	int data;
	Node* next;

};

int main(){

	int n;
	scanf("%d", &n);

	Node *head, *q, *p;
	head = new Node;
	head->next = head;

	q = head;
	for (int i = 0; i < n; i++)
	{
		p = new Node;

		scanf("%d", &p->data);

		q->next= p;
		p->next = head;

		q = p;
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		p = new Node;

		scanf("%d", &p->data);

		q->next= p;
		p->next = head;

		q = p;
	}

	p = head->next;
	while ( p != head )
	{
		printf("%d", p->data);
		if ( p->next != head ) printf(" ");
		else printf("\n");

		p = p->next;
	}

	system("pause");
	return 0;
}
