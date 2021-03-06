#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		while ( n-- )
		{
			//k:输入的整数数量
			int k;
			scanf("%d", &k);

			vector<int> nums;

			int num;
			for (int i = 0; i < k; i++)
			{
				scanf("%d", &num);
				nums.push_back(num);
			}

			vector<int> ans;

			for (int i = 0; i < nums.size(); i++)
			{
				if ( i == 0 && nums[i] != nums[i+1] ) ans.push_back(i);
				else if ( i == k - 1 && nums[i] != nums[i-1] ) ans.push_back(i);
				else if ( nums[i] < nums[i-1] && nums[i] < nums[i+1] ) ans.push_back(i);
				else if ( nums[i] > nums[i-1] && nums[i] > nums[i+1] ) ans.push_back(i);
			}

			for (int i = 0; i < ans.size(); i++)
			{
				printf("%d", ans[i]);
				if ( i < ans.size() - 1 ) printf(" ");
				else printf("\n");
			}
		}
	}
	system("pause");
	return 0;
}
