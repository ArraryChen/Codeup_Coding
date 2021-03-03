#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 100;

int main(){

	int m;
	scanf("%d", &m);

	while ( m )
	{
		char str1[maxn], str2[maxn];
		scanf("%s %s", str1, str2);

		int len1 = strlen(str1), len2 = strlen(str2);

		if ( len1 == len2 ) printf("%s is equal long to %s\n", str1, str2);
		else if ( len1 < len2 ) printf("%s is shorter than %s\n", str1, str2);
		else printf("%s is longer than %s\n", str1, str2);

		m--;
	}

	system("pause");
	return 0;
}
