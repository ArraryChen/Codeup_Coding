#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	//�ϲ���-�����n��
	for (int i = 1; i <= n; i++)
	{
		//�������һ���Ǻ�ǰ��Ŀո�
		for (int j = 1; j < i; j++)
		{
			printf(" ");
		}
		//����м����
		for (int j = 0; j < n - i + 1; j++)
		{
			printf("*");
			if ( j < n - i ) printf(" ");
		}
		//��������һ���ͺź���Ŀո�
		for (int j = 1; j < i; j++)
		{
			printf(" ");
		}
		printf("\n");
	}

	//�²���-�����n-1��
	for (int i = 1; i <= n - 1; i++)
	{
		//�Գ���һ���ͺ�ǰ��Ŀո�
		for (int j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}
		//����м����
		for (int j = 0; j < i + 1; j++)
		{
			printf("*");
			if ( j < i ) printf(" ");
		}
		//��������һ���ͺź���Ŀո�
		for (int j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
