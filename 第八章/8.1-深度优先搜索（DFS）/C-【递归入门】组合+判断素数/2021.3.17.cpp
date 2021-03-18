#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int n, k, sum;
int number[25], count1;

bool isPrime(int n){

	if ( n <= 1 ) return false;
	else
	{
		int sqr = (int)sqrt(1.0 * n);
		for (int i = 2; i <= sqr; i++)
		{
			if ( n % i == 0 )
			{
				return false;
			}
		}
		return true;
	}
}

void generate(int pos, int level){

	if ( level == k )
	{
		if ( isPrime(sum) )
		{
			count1++;
		}
		return;
	}

	for (int i = pos; i < n; i++)
	{
		sum += number[i];
		generate(i + 1, level + 1);
		sum -= number[i];
	}
}


int main(){

	while ( scanf("%d %d", &n, &k) != EOF )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &number[i]);
		}

		count1 = sum = 0;

		generate(0, 0);

		printf("%d\n", count1);
	}

	system("pause");
	return 0;
}
