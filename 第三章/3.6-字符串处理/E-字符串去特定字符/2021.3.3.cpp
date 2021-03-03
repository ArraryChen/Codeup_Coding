#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 100010;

int main(){

	char str[maxn];
	
	char ch;
	while ( cin.getline(str, maxn) )
	{
		scanf("%c", &ch);
		getchar();

		int i = 0;
		while ( str[i] != '\0' )
		{
			if ( str[i] != ch ) printf("%c", str[i]);
			i++;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
