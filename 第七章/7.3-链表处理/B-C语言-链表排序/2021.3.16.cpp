#include<cstdio>
#include<iostream>

using namespace std;

struct Node{

	int id;
	int score;
	Node * next;

};

void insert(Node *a, Node *q){

	//pre:待插入位置的前驱结点
	//p:待插入位置的后置结点
	Node *pre, *p;

	//初始化
	pre = a, p = a->next;
	
	//找到待插入的位置
	while ( p && p->id < q->id )
	{
		pre = p;
		p = p->next;
	}

	//将待插入结点的next设置为p,前驱结点pre的next设置为q
	q->next = p;
	pre->next = q;
}


int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	//head:头结点
	//p:临时指针
	Node *head, *p;

	head = new Node;
	head->next= NULL;

	//循环插入n + m个结点
	for (int i = 0; i < n + m; i++)
	{
		p = new Node;

		scanf("%d %d", &p->id, &p->score);

		insert(head, p);
	}

	p = head->next;

	//输出
	while ( p )
	{
		printf("%d %d\n", p->id, p->score);

		p = p->next;
	}

	system("pause");
	return 0;
}
