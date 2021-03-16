#include<cstdio>
#include<iostream>

using namespace std;

struct Node{

	int id;
	int score;
	Node * next;

};

void insert(Node *a, Node *q){

	//pre:������λ�õ�ǰ�����
	//p:������λ�õĺ��ý��
	Node *pre, *p;

	//��ʼ��
	pre = a, p = a->next;
	
	//�ҵ��������λ��
	while ( p && p->id < q->id )
	{
		pre = p;
		p = p->next;
	}

	//�����������next����Ϊp,ǰ�����pre��next����Ϊq
	q->next = p;
	pre->next = q;
}


int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	//head:ͷ���
	//p:��ʱָ��
	Node *head, *p;

	head = new Node;
	head->next= NULL;

	//ѭ������n + m�����
	for (int i = 0; i < n + m; i++)
	{
		p = new Node;

		scanf("%d %d", &p->id, &p->score);

		insert(head, p);
	}

	p = head->next;

	//���
	while ( p )
	{
		printf("%d %d\n", p->id, p->score);

		p = p->next;
	}

	system("pause");
	return 0;
}
