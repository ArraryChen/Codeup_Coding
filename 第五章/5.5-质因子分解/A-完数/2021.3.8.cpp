#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		vector<int> nums;
		for (int i = 1; i <= n; i++)
		{
			vector<int> ans;

			//找出 i 的所有因数,存入ans
			for (int j = 1; j < i; j++)
			{
				if ( i % j == 0 )
				{
					ans.push_back(j);
				}
			}

			//把 i 的所有因数相加,和数存入sum
			int sum = 0;
			for (int j = 0; j < ans.size(); j++)
			{
				sum += ans[j];
			}
			if ( sum == i )
			{
				nums.push_back(i);
			}
		}

		//循环输出
		for (int i = 0; i < nums.size(); i++)
		{
			printf("%d", nums[i]);
			if ( i < nums.size() - 1 ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}
