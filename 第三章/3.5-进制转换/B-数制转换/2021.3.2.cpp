#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main(){

	int a, b;
	char str[100];
	
	while ( scanf("%d %s %d", &a, str, &b) != EOF )
	{
		//注意:不要忘了0的情况
		if ( str[0] == '0' )
		{
			printf("0\n");
			continue;
		}

		char result[100];
		
		long long sum = 0;

		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			if ( str[i] >= '0' && str[i] <= '9' ) sum = sum * a + ( str[i] - '0' );
			else if ( str[i] >= 'a' && str[i] <= 'f' ) sum = sum * a + ( str[i] - 'a' + 10);
			else if ( str[i] >= 'A' && str[i] <= 'F' ) sum = sum * a + ( str[i] - 'A' + 10);
		}

		//得到sum是n的十进制数
		if ( b == 10 ) printf("%lld\n", sum);
		else
		{
			int length = 0;
			while ( sum )
			{
				int temp = sum % b;
				if ( temp >= 0 && temp <= 9 ) result[length++] = temp + '0';
				else if( temp >= 10 && temp <= 16 ) result[length++] = temp - 10 + 'A';

				sum /= b;
			}
			for (int i = length - 1; i >= 0; i--)
			{
				printf("%c", result[i]);
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}
