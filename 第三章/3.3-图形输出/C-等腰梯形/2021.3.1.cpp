#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	while ( n )
	{
		int m;
		scanf("%d", &m);

		//π≤”–m––
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < m - i; j++)
			{
				printf(" ");
			}
			for (int j = 0; j < m + (i-1) * 2; j++)
			{
				printf("*");
			}
			for (int j = 0; j < m - 1; j++)
			{
				printf(" ");
			}
			printf("\n");
		}
		n--;
	}

	system("pause");
	return 0;
}
