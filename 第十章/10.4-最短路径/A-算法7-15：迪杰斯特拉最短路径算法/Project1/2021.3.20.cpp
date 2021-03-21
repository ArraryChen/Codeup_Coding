#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 100;
const int INF = 1000000000;

int n, s, G[maxv][maxv], d[maxv];
bool vis[maxv];

void Dijkstra(int s){
	
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

int main(){

	while ( scanf("%d %d", &n, &s) != EOF )
	{
		//初始化: visit数组, 图, d数组
		memset(vis, false, sizeof(vis));
		fill(G[0] ,G[0] + maxv, 0);
		fill(d, d + maxv, INF);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &G[i][j]);
			}
		}

		Dijkstra(s);

		for (int i = 0; i < n; i++)
		{
			if ( i == s ) 
				continue;
			
			if (d[i] == INF)
				printf("-1");
			else
				printf("%d", d[i]);
			
			if ( i < n - 1 ) 
				printf(" ");
			else
				printf("\n");
		}
	}

	system("pause");
	return 0;
}
