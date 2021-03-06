#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 10010;

int main(){

	int num[maxn];

	int n;
	while ( scanf("%d", &n) != EOF, n )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		sort(num, num + n);

		if ( n % 2 == 0 ) printf("%d\n", ( num[n/2-1] + num[n/2] ) / 2 );
		else printf("%d\n", num[n/2]);
	}

	system("pause");
	return 0;
}