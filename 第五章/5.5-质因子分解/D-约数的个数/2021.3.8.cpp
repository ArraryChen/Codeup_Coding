#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		while ( n-- )
		{
			int num;
			scanf("%d", &num);

			int count = 0;
			for (int i = 1; i <= (int)sqrt(1.0 * num); i++)
			{
				if ( num % i == 0 )
				{
					if ( i == sqrt(1.0 * num) )
					{
						count++;
						break;
					}
					else
					{
						count += 2;
					}
				}
			}
			printf("%d\n", count);
		}
	}

	system("pause");
	return 0;
}
