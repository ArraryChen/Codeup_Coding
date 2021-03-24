#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 5010;

int dp[maxn][maxn];

int main(){

	char input[maxn];
	while ( cin.getline(input, maxn) )
	{
		memset(dp, 0, sizeof(dp));

		//len:输入字符串的长度
		//length:剩余字母和数字的字符串长度
		//pos:剩余字母和数字在原字符串中的位置
		int len = strlen(input), length = 0, pos[maxn];
		
		//str:剩余字母和数字的字符串
		char str[maxn];

		//存储字符串
		for (int i = 0; i < len; i++)
		{
			if ( input[i] >= 'a' && input[i] <= 'z' )
			{
				str[length] = input[i];
				pos[length++] = i;
			}
			else if ( input[i] >= 'A' && input[i] <= 'Z' )
			{
				str[length] = input[i] - 'A' + 'a';
				pos[length++] = i;
			}
			else if ( input[i] >= '0' && input[i] <= '9' )
			{
				str[length] = input[i];
				pos[length++] = i;
			}
		}
		
		int ans = 1, start = 0;
		for (int i = 0; i < length; i++)
		{
			dp[i][i] = 1;
			if ( i < length - 1 )
			{
				if ( str[i] == str[i+1] )
				{
					dp[i][i+1] = 1;
					start = i;
					ans = 2;
				}
			}
		}

		for (int L = 3; L <= length; L++)
		{
			for (int i = 0; i + L - 1 < length; i++)
			{
				int j = i + L - 1;
				if (str[i] == str[j] && dp[i+1][j-1] == 1)
				{
					dp[i][j] = 1;
					start = i;
					ans = L;
				}
			}
		}

		for(int i= pos[start]; i <= pos[start+ans-1]; i++)
		{
			printf("%c", input[i]);
		}

		printf("\n");
	}//while end

	system("pause");
	return 0;
}
