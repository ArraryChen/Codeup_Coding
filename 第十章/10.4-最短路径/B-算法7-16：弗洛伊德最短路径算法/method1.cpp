方法一:依次对每个结点调用Dijkstra

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 55;
const int INF = 1000000000;

int n;
int G[maxv][maxv], d[maxv];
bool vis[maxv];

void Dijstra(int s){

	d[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++)
		{
			if ( vis[j] == false && d[j] < MIN )
			{
				u = j;
				MIN = d[j];
			}
		}

		if (u == -1) return;
		vis[u] = true;

		for (int v = 0; v < n; v++)
		{
			if ( vis[v] == false && G[u][v] != 0 && d[u] + G[u][v] < d[v] )
			{
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

void DFSTrave(){
	
	for (int i = 0; i < n; i++)
	{
		memset(vis, false, sizeof(vis));
		fill(d, d + maxv, INF);

		Dijstra(i);

		for (int j = 0; j < n; j++)
		{
			if (d[j] == INF)
				printf("-1");
			else
				printf("%d", d[j]);

			if (j < n - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
}

int main(){

	while ( scanf("%d", &n) != EOF && n )
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &G[i][j]);
			}
		}
		DFSTrave();
	}

	system("pause");
	return 0;
}
