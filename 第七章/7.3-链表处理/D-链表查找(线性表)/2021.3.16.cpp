#include<cstdio>
#include<iostream>

using namespace std;

struct node{

	int data;
	node *next;

};

void insert(node *head, node *p){

	node *pre, *q;

	pre = head, q = head->next;

	while ( q && p->data > q->data )
	{
		pre = q;
		q = q->next;
	}

	p->next = q;
	pre->next= p;
}


int main(){

	int x;
	scanf("%d", &x);

	int n;
	scanf("%d", &n);

	node *head, *p;
	head = new node;
	head->next = NULL;

	for (int i = 0; i < n; i++)
	{
		p = new node;
		scanf("%d", &p->data);

		insert(head, p);
	}

	p = head;
	while ( p )
	{
		if ( p->next->data < x ) p = p->next;
		else break;
	}

	if ( p && p->next->data == x )
	{
		swap(p->next->data, p->next->next->data);
	}
	else
	{
		node *temp = new node;
		temp->data = x;

		temp->next = p->next;
		p->next = temp;

		printf("no\n");
	}

	p = head->next;
	while ( p )
	{
		printf("%d", p->data);

		if ( p->next != NULL ) printf(" ");
		else printf("\n");

		p = p->next;
	}

	system("pause");
	return 0;
}
