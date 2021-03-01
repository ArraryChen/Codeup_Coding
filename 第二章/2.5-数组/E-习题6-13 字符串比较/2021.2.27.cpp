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

	char str1[maxn], str2[maxn];

	gets(str1);
	gets(str2);

	int num = compareTwoStr(str1, str2);

	printf("%d", num);


	system("pause");
	return 0;
}
