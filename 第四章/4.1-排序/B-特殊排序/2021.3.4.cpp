#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 1010;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;

		//num:保存输入的数字
		//temp:暂存当前输入的数字
		int num[maxn], temp;

		//循环输入
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			num[i] = temp;
		}

		//排序
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

		//输出最大值
		printf("%d\n", num[n-1]);
		if ( n == 1 )
		{
			 printf("-1\n");
			 continue;
		}

		//若输入的整数数量超过一个
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
