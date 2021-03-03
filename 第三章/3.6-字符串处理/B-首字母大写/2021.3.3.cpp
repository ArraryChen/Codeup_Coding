#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 110;

int main(){

	char str[maxn];
	while ( cin.getline(str, maxn) )
	{
		int i = 0;
		while ( str[i] != '\0' )
		{
			if ( i == 0 )
			{
				if ( str[i] >= 'a' && str[i] <= 'z' )
				{
					str[i] = str[i] - 'a' + 'A';
				}
			}
			else if ( str[i] >= 'a' && str[i] <= 'z' )
			{
				if ( str[i-1] == ' ' || str[i-1] == '\t' || str[i-1] == '\r' || str[i-1] == '\n' )
				{
					str[i] = str[i] - 'a' + 'A';
				}
			}
			i++;
		}
		printf("%s\n", str);
	}
	system("pause");
	return 0;
}
