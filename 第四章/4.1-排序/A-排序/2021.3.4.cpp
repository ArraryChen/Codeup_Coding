#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 110;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;
		int num[maxn];
		int input;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &input);
			num[i] = input;
		}

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if ( num[j] > num[j+1] )
				{
					int temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d", num[i]);
			if ( i < n - 1 ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}
