#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		int tree[1010];

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &tree[i]);
		}

		int level;
		scanf("%d", &level);

		if ( pow(2, level-1) > n )
		{
			printf("EMPTY\n");
		}
		else
		{
			int end = pow(2, level);
			for (int i = pow(2, level - 1); i < end; i++)
			{
				printf("%d", tree[i]);
				if ( i < end - 1 ) printf(" ");
				else printf("\n");
			}
		}
	}
	system("pause");
	return 0;
}
