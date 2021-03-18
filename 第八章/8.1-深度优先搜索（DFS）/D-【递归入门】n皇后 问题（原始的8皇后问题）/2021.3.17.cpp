#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int n, P[20], hashTable[20] = {false};

bool fg;

void generate(int index){

	if ( index == n + 1 )
	{
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if ( abs(i - j) == abs(P[i] - P[j]) )
				{
					flag = false;
				}
			}
		}
		if ( flag )
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d", P[i]);
				if ( i < n ) printf(" ");
				else printf("\n");
			}
			fg = true;
		}
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if ( hashTable[i] == false )
		{
			P[index] = i;
			hashTable[i] = true;
			generate(index + 1);
			hashTable[i] = false;
		}
	}
}

int main(){
	while ( scanf("%d", &n) != EOF )
	{
		fg = false;
		generate(1);

		if ( fg == false ) printf("no solute!\n");
	}

	system("pause");
	return 0;
}
