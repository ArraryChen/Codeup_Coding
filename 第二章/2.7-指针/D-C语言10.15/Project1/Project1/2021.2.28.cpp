#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 1010;

int compareStr(char str1[], char str2[]){

	int i = 0, j = 0;

	while ( str1[i] != '\0' && str2[j] != '\0' )
	{
		if ( str1[i] != str2[j] ) break;

		i++;
		j++;
	}
	return str1[i] - str2[j];
}


int main(){

	char str1[maxn], str2[maxn], str3[maxn];
	scanf("%s %s %s", str1, str2, str3);

	int num1 = compareStr(str1, str2);
	int num2 = compareStr(str1, str3);
	int num3 = compareStr(str2, str3);

	if ( num1 <= 0 && num2 <= 0 )
	{
		if ( num3 <= 0 ) // stsr1 < str2 < str3
		{
			printf("%s\n%s\n%s\n", str1, str2, str3);
		}
		else // str1 < str3 < str2
		{
			printf("%s\n%s\n%s\n", str1, str3, str2);
		}
	}
	else if ( num1 >= 0 && num3 <= 0 )
	{
		if ( num2 <= 0 ) // str2 < str1 < str3
		{
			printf("%s\n%s\n%s\n", str2, str1, str3);
		}
		else // str2 < str3 < str1
		{
			printf("%s\n%s\n%s\n", str2, str3, str1);
		}
	}
	else if ( num2 >= 0 && num3 >= 0 )
	{
		if ( num1 <= 0 ) // str3 < str1 < str2
		{
			printf("%s\n%s\n%s\n", str3, str1, str2);
		}
		else // str3 < str2 < str1
		{
			printf("%s\n%s\n%s\n", str3, str2, str1);
		}
	}

	system("pause");
	return 0;
}
