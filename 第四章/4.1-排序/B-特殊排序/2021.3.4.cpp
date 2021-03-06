#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 1010;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;

		//num:�������������
		//temp:�ݴ浱ǰ���������
		int num[maxn], temp;

		//ѭ������
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			num[i] = temp;
		}

		//����
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if ( num[j] > num[j+1] )
				{
					int temp_num = num[j];
					num[j] = num[j+1];
					num[j+1] = temp_num;
				}
			}
		}

		//������ֵ
		printf("%d\n", num[n-1]);
		if ( n == 1 )
		{
			 printf("-1\n");
			 continue;
		}

		//�������������������һ��
		for (int i = 0; i < n - 1; i++)
		{
			printf("%d", num[i]);
			if ( i < n - 2 ) printf(" ");
			else printf("\n");
		}
	}
	system("pause");
	return 0;
}
