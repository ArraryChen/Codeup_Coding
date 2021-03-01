#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 5 ; j++)
		{
			printf("%3d", i * j);
			if( j == 5 ) printf("\n");
		}
	}

	system("pause");
	return 0;
}
