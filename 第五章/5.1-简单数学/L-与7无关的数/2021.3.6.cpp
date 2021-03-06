#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if ( i % 7 != 0 )
			{
				if ( i > 10 )
				{
					int a = i % 10, b = i / 10;
					if ( a != 7 && b != 7 ) sum += i * i;
				}
				else sum += i * i;
			}
		}
		printf("%d\n", sum);
	}

	system("pause");
	return 0;
}
