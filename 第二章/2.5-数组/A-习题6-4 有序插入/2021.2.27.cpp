#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int num[10];
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
	}

	scanf("%d", &num[9]);

	//тксцакц╟ещеепР
	for (int i = 1; i <= 9 ; i++)
	{
		for (int j = 0; j < 10 - i; j++)
		{
			if ( num[j] > num[j+1] )
			{
				int temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", num[i]);
	}

	system("pause");
	return 0;
}
