#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int num[20][20];

	//�����(�е����ұ�)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ( i == j )
			{
				num[i][j] = 1;
			}
		}
	}

	//���ڲ�(�е������)
	for (int i = 1; i < n; i++)
	{
		num[i][0] = 1;
	}

	//�м��
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			//��������:ÿ�����������Ϸ�����֮��
			num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
		}
	}

	//���
	for (int i = 0; i < n; i++) //����n��
	{
		for (int j = 0; j < i + 1; j++) //ÿ�е�Ԫ��Ϊ i+1 ��
		{
			printf("%d", num[i][j]);
			if ( j < i ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}
