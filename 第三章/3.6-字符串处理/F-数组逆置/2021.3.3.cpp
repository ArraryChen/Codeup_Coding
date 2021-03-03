#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 100010;

int main(){

	char str[maxn];
	while ( cin.getline(str, maxn) )
	{
		int length = strlen(str);
		for (int i = length - 1; i >= 0; i--)
		{
			printf("%c", str[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
