#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		vector<int> nums;

		int num;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			nums.push_back(num);
		}

		int	m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &num);
			
			bool result = false;
			for (int j = 0; j < nums.size(); j++)
			{
				if ( num == nums[j] )
				{
					result = true;
					break;
				}
			}
			if ( result ) printf("YES\n");
			else printf("NO\n");
		}
	}

	system("pause");
	return 0;
}
