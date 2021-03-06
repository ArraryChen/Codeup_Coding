#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		while ( n-- )
		{
			int a;
			scanf("%d", &a);

			if ( a % 2 == 1 ) printf("0 0\n");
			else if ( a % 4 == 0 ) printf("%d %d\n", a/4, a/2);
			else printf("%d %d\n", a/4+1, a/2);
		}
	}

	system("pause");
	return 0;
}
