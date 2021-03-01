#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int sum = 0, i = 1;

	while (1)
	{
		if ( i == n )
		{
			sum += i++;
			break;
		}
		sum += i++;
	}

	printf("%d\n", sum);

	system("pause");
	return 0;
}
