#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		while ( n-- )
		{
			int num, sum = 0;
			scanf("%d", &num);

			if ( num >= 0 )
			{
				for (int i = num; i <= 2 * num; i++)
				{
					sum += i;
				}
			}
			else
			{
				for (int i = num; i >= 2 * num; i--)
				{
					sum += i;
				}
			}

			printf("%d\n", sum);
		}
	}

	system("pause");
	return 0;
}
