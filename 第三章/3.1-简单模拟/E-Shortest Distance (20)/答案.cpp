#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 100010;

//dis����:������㵽�������ľ���
int dis[maxn] = {0};

int main(){

	//n:�����
	int n;
	scanf("%d", &n);

	//distance:��ʱ����,����������������ľ���
	//sum:��������(���1)���յ�(���n)�ľ���
	int distance = 0, sum = 0;

	//ѭ���������ľ���
	//����sumͳ�ƴ����(���1)���������ľ���,����dis������
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &distance);
		sum += distance;

		dis[i] = sum;
	}

	//m:������m�Խ�����̾���
	int m;
	scanf("%d", &m);

	//left, right:���Ҷ˵�
	int left, right;

	//ѭ������
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &left, &right);
		if ( left > right ) swap( left, right );		//Ϊ�˱��ڼ���,����˵���Ϊ������Сֵ,�Ҷ˵���Ϊ�������ֵ

		int temp = dis[right - 1] - dis[left - 1];		//ͳ�ƴӶ˵� left->right ���������
		printf("%d\n", min(temp, sum - temp));			//���ڴӶ˵� left->right ���������ͷ������(��ͼ�Ǹ���),������Сֵ��Ϊ���·��
	}

	system("pause");
	return 0;
}
