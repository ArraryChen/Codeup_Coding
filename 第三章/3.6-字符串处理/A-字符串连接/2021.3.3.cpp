#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 110;

int main(){

	char str1[maxn], str2[maxn];

	while ( scanf("%s %s", str1, str2) != EOF )
	{
		int i = 0;
		while ( str1[i] != '\0' ) i++;

		int j = 0;
		while ( str2[j] != '\0' )
		{
			str1[i++] = str2[j++];
		}
		str1[i] = '\0';
		printf("%s\n",str1);
	}

	system("pause");
	return 0;
}
