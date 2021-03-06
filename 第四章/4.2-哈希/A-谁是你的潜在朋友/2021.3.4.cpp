#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n, m;
	while ( scanf("%d %d", &n, &m) != EOF)
	{
		if ( n == 0 || m == 0 ) break;

		int count[210] = { 0 };
		int like[210];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &like[i]);
			count[like[i]]++;
		}

		for (int i = 0; i < n; i++)
		{
			if ( count[like[i]] == 1 ) printf("BeiJu\n");
			else printf("%d\n", count[like[i]] - 1);
		}
	}

	system("pause");
	return 0;
}
