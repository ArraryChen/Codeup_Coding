#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	while ( n != 0 )
	{
		int m;
		scanf("%d", &m);

		int sum = 0, num;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n\n", sum);
		n--;
	}

	system("pause");
	return 0;
}
