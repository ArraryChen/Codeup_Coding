#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 55;
const int INF = 1000000000;

int n;
int d[maxv][maxv];

void Floyd(){

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ( d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j] )
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}

int main(){

	while ( scanf("%d", &n) != EOF )
	{
		fill(d[0], d[0] + maxv * maxv, INF);

		int w;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &w);
				if ( w == 0 )
					d[i][j] = INF;
				else
					d[i][j] = w;
			}
		}

		for (int i = 0; i < n; i++)
		{
			d[i][i] = 0;
		}

		Floyd();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ( d[i][j] == INF )
					printf("-1");
				else
					printf("%d", d[i][j]);
				
				if (j < n - 1)
					printf(" ");
				else
					printf("\n");
			}
		}
	}

	system("pause");
	return 0;
}
