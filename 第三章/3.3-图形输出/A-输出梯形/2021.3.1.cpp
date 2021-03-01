#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int h;
	while ( scanf("%d", &h) != EOF )
	{
		for (int i = 1; i <= h; i++)
		{
			for (int j = 0; j < ( h - i ) * 2; j++)
			{
				printf(" ");
			}
			for (int j = 0; j < h + ( i - 1 ) * 2; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}
