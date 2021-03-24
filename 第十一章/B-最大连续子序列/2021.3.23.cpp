#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 10010;

int nums[maxn], d[maxn];

int main(){

	int n;

	while ( scanf("%d", &n) != EOF && n )
	{
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &nums[i]);
			if (nums[i] >= 0) flag = true;
		}

		if ( flag == false )
		{
			printf("0 %d %d\n", nums[0], nums[n-1]);
			continue;
		}

		d[0] = nums[0];
		for (int i = 1; i < n; i++)
		{
			d[i] = max(nums[i], d[i-1] + nums[i]);
		}

		int k = 0;
		for (int i = 1; i < n; i++)
		{
			if ( d[i] > d[k] )
			{
				k = i;
			}
		}

		int j = k;
		while ( j >= 0 )
		{
			if ( nums[j] < d[j-1] + nums[j] )
			{
				j--;
			}
			else
				break;
		}
		printf("%d %d %d\n", d[k], nums[j], nums[k]);
	}


	system("pause");
	return 0;
}
