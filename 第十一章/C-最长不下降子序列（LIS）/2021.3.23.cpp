#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int nums[1010], dp[1010];

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &nums[i]);
		}

		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if ( nums[i] > nums[j] )
				{
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
			ans = max(ans, dp[i]);
		}

		printf("%d\n", ans);
	}


	system("pause");
	return 0;
}
