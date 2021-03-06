#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int x, n;
	while ( scanf("%d %d", &x, &n) != EOF )
	{
		double yn = x;

		for (int i = 0; i < n; i++)
		{
			yn = yn * (2 / 3.0) + x / (3 * yn * yn);
		}

		printf("%.6f\n", yn);
	}

	system("pause");
	return 0;
}
