#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 110;

int dp[maxn][maxn];

int main(){

	char str1[maxn], str2[maxn];
	
	while ( scanf("%s %s", str1+1, str2+1) != EOF )
	{

		int len1 = strlen(str1 + 1);
		int len2 = strlen(str2 + 1);

		for (int i = 0; i <= len1; i++)
		{
			dp[i][0] = 0;
		}
		for (int i = 0; i <= len2; i++)
		{
			dp[0][i] = 0;
		}

		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if ( str1[i] == str2[j] )
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				}
			}
		}
		printf("%d\n", dp[len1][len2]);
	}


	system("pause");
	return 0;
}
