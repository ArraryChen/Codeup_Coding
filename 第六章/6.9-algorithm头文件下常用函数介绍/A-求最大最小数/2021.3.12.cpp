#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		vector<int> nums;

		int num;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			nums.push_back(num);
		}

		sort(nums.begin(), nums.end());

		printf("%d %d\n", nums[nums.size() - 1], nums[0]);
	}

	system("pause");
	return 0;
}
