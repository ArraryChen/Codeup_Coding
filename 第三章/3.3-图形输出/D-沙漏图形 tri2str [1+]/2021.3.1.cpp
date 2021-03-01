#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	//上部分-先输出n行
	for (int i = 1; i <= n; i++)
	{
		//先输出第一个星号前面的空格
		for (int j = 1; j < i; j++)
		{
			printf(" ");
		}
		//输出中间的星
		for (int j = 0; j < n - i + 1; j++)
		{
			printf("*");
			if ( j < n - i ) printf(" ");
		}
		//再输出最后一个型号后面的空格
		for (int j = 1; j < i; j++)
		{
			printf(" ");
		}
		printf("\n");
	}

	//下部分-再输出n-1行
	for (int i = 1; i <= n - 1; i++)
	{
		//显出第一个型号前面的空格
		for (int j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}
		//输出中间的星
		for (int j = 0; j < i + 1; j++)
		{
			printf("*");
			if ( j < i ) printf(" ");
		}
		//再输出最后一个型号后面的空格
		for (int j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
