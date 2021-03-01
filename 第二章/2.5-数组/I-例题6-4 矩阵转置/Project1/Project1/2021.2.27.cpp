#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int num1[2][3], num2[3][2];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &num1[i][j]);
			num2[j][i] = num1[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d", num2[i][j]);
			if ( j < 1 ) printf(" ");
			else printf("\n");
		}
	}


	system("pause");
	return 0;
}
