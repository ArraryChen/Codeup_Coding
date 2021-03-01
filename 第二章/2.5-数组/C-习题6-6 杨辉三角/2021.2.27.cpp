#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int num[20][20];

	//最外层(行的最右边)
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

	//最内层(行的最左边)
	for (int i = 1; i < n; i++)
	{
		num[i][0] = 1;
	}

	//中间层
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			//利用性质:每个数等于它上方两数之和
			num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
		}
	}

	//输出
	for (int i = 0; i < n; i++) //共有n行
	{
		for (int j = 0; j < i + 1; j++) //每行的元素为 i+1 个
		{
			printf("%d", num[i][j]);
			if ( j < i ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}
