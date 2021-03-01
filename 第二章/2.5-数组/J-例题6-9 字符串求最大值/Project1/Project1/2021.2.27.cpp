#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 10010;

int compareTwoStr(char str1[], char str2[]){

	int i = 0, j = 0;

	while ( str1[i] != '\0' && str2[j] != '\0' )
	{
		if ( str1[i] != str2[j] )
		{
			break;
		}
		else
		{
			i++;
			j++;
		}
	}

	return str1[i] - str2[j];

}


int main(){

	char str1[maxn], str2[maxn], str3[maxn];

	gets(str1);
	gets(str2);
	gets(str3);

	int num1 = compareTwoStr(str1, str2);
	int num2 = compareTwoStr(str1, str3);
	int num3 = compareTwoStr(str2, str3);

	if ( num1 >= 0 && num2 >= 0 )
	{
		printf("%s", str1);
	}
	else if ( num1 <= 0 && num3 >= 0 )
	{
		printf("%s", str2);
	}
	else if ( num2 <= 0 && num3 <= 0 )
	{
		printf("%s", str3);
	}

	system("pause");
	return 0;
}
