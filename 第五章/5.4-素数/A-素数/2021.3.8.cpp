#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n > 1 )
	{
		vector<int> ans;

		for (int i = 2; i < n; i++)
		{
			bool result = true;
			for (int j = 2; j <= i / 2; j++)
			{
				if ( i % j == 0 )
				{
					result = false;
					break;
				}
			}
			if ( result && i % 10 == 1 ) ans.push_back(i);
		}

		if ( ans.size() == 0 ) printf("-1\n");
		else
		{
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
