#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	int m, n;
	while ( scanf("%d %d", &m, &n) != EOF )
	{
		if ( m == 0 || n == 0 ) break;

		vector<int> nums;
		int num;

		for (int i = 0; i < m; i++)
		{
			scanf("%d", &num);
			nums.push_back(num);
		}

		sort(nums.begin(), nums.end());

		printf("%d\n", nums[m - n]);
	}
	system("pause");
	return 0;
}
