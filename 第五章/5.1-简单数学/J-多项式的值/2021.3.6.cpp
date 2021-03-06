#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	//m:样例数
	int m;
	while ( scanf("%d", &m) != EOF )
	{
		while ( m-- )
		{
			//n:最高项数
			int n;
			scanf("%d", &n);

			//nums:保存系数
			vector<int> nums;

			//num:临时变量
			int num;

			//循环输入系数
			for (int i = 0; i <= n; i++)
			{
				scanf("%d", &num);
				nums.push_back(num);
			}

			int x;
			scanf("%d", &x);
		
			//sum:多项式的值
			int sum = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				//常数项无需乘上x
				if ( i == 0 ) 
				{
					sum = nums[0];
					continue;
				}
				//计算本次需要乘上x的个数
				int count = 1;
				for (int j = 0; j < i; j++)
				{
					count *= x;
				}
				//求和
				sum += nums[i] * count;
			}
			printf("%d\n", sum);
		}
	}

	system("pause");
	return 0;
}
