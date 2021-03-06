#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF, n )
	{
		double money = 0;

		//(0, 4)
		if ( n < 4 )
		{
			money += 10;
		}
		//[4, 8]
		else if ( n >= 4 && n < 8 )
		{
			money = 10 + (n - 4) * 2;
		}
		//(8, +¡Þ)
		else if ( n >= 8 )
		{
			while ( n >= 8 )
			{
				money += 18;
				n -= 8;
			}

			if ( n <= 4 )
			{
				money += n * 2.4;
			}
			else
			{
				money += 10 + (n - 4) * 2;
			}
		}

		if (money - (int)money == 0) printf("%d\n", (int)money);
		else printf("%.1f\n", money);
	}
	system("pause");
	return 0;
}
