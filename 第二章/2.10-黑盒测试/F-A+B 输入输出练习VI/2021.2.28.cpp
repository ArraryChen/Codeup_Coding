#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF)
	{
		if ( n == 0 ) break;
		int num, sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}

	system("pause");
	return 0;
}
