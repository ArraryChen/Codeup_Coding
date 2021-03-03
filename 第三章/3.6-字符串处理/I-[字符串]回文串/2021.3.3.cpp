#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 300;

bool judgeStr(char str[]){

	int len = strlen(str);

	for (int i = 0; i < len / 2; i++)
	{
		if ( str[i] != str[len-1-i] )
		{
			return false;
		}
	}
	return true;
}

int main(){

	char str[maxn];
	while ( scanf("%s", str) != EOF )
	{
		if ( judgeStr(str) ) printf("YES\n");
		else printf("NO\n");
	}

	system("pause");
	return 0;
}
