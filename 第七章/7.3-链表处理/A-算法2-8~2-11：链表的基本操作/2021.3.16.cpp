#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

typedef struct LNode{

	int data;
	LNode* next;

}LNode, *Linklist;

void create(Linklist &L, int n){

	Linklist p;

	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;

	//头插法
	for (int i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;;
		L->next = p;
	}
}

void show(Linklist L){

	Linklist p = L->next;

	if ( L->next == NULL )
	{
		printf("Link list is empty\n");
		return;
	}

	while ( p )
	{
		printf("%d", p->data);
		if ( p->next != NULL ) printf(" ");
		else printf("\n");
		p = p->next;
	}
}

void deleteNode(Linklist &L, int i){

	Linklist p, q;
	p = L;

	int j = 0;

	while ( p->next && j < i - 1 )
	{
		p = p->next;
		j++;
	}

	if ( !(p->next) || j > i - 1 )
	{
		printf("delete fail\n");
		return;
	}

	q = p->next;
	p->next = q->next;
	free(q);

	printf("delete OK\n");
	return;
}

void insertNode(Linklist &L, int i, int e){

	Linklist p, s;
	p = L;

	int j = 0;
	while ( p && j < i - 1 )
	{
		p = p->next;
		j++;
	}
	if ( !(p) || j > i - 1 )
	{
		printf("insert fail\n");
		return ;
	}

	s = (Linklist)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	printf("insert OK\n");
	return;
}

void getNode(Linklist &L, int i){

	Linklist p = L->next;

	int j = 1;

	while ( p && j < i )
	{
		p = p->next;
		j++;
	}

	if ( !p || j > i )
	{
		printf("get fail\n");
		return;
	}

	printf("%d\n", p->data);
	return;
}

int main(){

	Linklist head = NULL;

	int n;
	scanf("%d", &n);

	//初始化列表
	create(head, n);

	int line;
	scanf("%d", &line);

	char str[20];

	while ( line-- )
	{
		scanf("%s", str);

		if ( strcmp(str, "show") == 0 )
		{
			show(head);
		}
		else if ( strcmp(str, "delete") == 0 )
		{
			int num_pos;
			scanf("%d", &num_pos);

			deleteNode(head, num_pos);
		}
		else if ( strcmp(str, "insert") == 0 )
		{
			int a, e;
			scanf("%d %d", &a, &e);

			insertNode(head, a, e);
		}
		else if ( strcmp(str, "get") == 0 )
		{
			int a;
			scanf("%d", &a);

			getNode(head, a);
		}
	}

	system("pause");
	return 0;
}
