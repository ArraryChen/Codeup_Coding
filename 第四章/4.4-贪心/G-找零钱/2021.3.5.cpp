#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main(){

	int money;
	while( scanf("%d", &money) != EOF )
	{
		if ( money < 1 || money > 99 ) break;

		int count[5], value[5] = {50, 20, 10, 5, 1};
		memset(count, 0, sizeof(count));

		while ( money >= 50 )
		{
			count[0]++;
			money -= 50;
		}
		while ( money < 50 && money >= 20 )
		{
			count[1]++;
			money -= 20;
		}
		while ( money < 20 && money >= 10 )
		{
			count[2]++;
			money -= 10;
		}
		while ( money < 10 && money >= 5 )
		{
			count[3]++;
			money -= 5;
		}
		while ( money < 5 && money > 0 )
		{
			count[4]++;
			money -= 1;
		}

		int total = 0;
		for (int i = 0; i < 5; i++)
		{
			if ( count[i] != 0 ) total++;
		}

		for (int i = 0; i < 5; i++)
		{
			if ( count[i] != 0 )
			{
				printf("%d*%d", value[i], count[i]);
				total--;
				if (total > 0) printf("+");
				else printf("\n");
			}
		}
	}
	system("pause");
	return 0;
}