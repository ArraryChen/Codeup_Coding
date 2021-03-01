#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10010;

int strToInt(char str[]){

	int sign = 1, i = 0;
	if ( str[0] == '-' )
	{
		 sign = -1;
		 i = 1;
	}

	int num = 0;
	while ( str[i] != '\0' )
	{
		if ( str[i] == ',' )
		{
			i++;
			continue;
		}
		else
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
	}
	return num * sign;
}


int main(){

	char str1[maxn], str2[maxn];
	while ( scanf("%s %s", str1, str2) != EOF )
	{
		int num1 = strToInt(str1);
		int num2 = strToInt(str2);

		printf("%d\n", num1 + num2);
	}

	system("pause");
	return 0;
}
