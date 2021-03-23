//方法一:邻接矩阵

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 110;
const int INF = 1000000000;

int n, d[maxv], G[maxv][maxv];
bool vis[maxv];

int Prim(){

	d[1] = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 1; j <= n; j++)
		{
			if ( vis[j] == false && d[j] < MIN )
			{
				u = j;
				MIN = d[j];
			}
		}

		if (u == -1) return -1;
		vis[u] = true;

		ans += d[u];

		for (int v = 1; v <= n; v++)
		{
			if ( vis[v] == false && G[u][v] != INF && G[u][v] < d[v] )
			{
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}

int main(){

	while ( scanf("%d", &n) != EOF && n )
	{
		memset(vis, false, sizeof(vis));
		fill(d, d + maxv, INF);
		fill(G[0], G[0] + maxv * maxv, INF);

		int u, v, dis;
		for (int i = 0; i < n*(n-1)/2; i++)
		{
			scanf("%d %d %d", &u, &v, &dis);
			G[u][v] = G[v][u] = dis;
		}

		int ans = Prim();

		printf("%d\n", ans);
	}

	system("pause");
	return 0;
}
