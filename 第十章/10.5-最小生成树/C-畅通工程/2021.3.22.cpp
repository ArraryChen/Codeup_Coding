//方法二:邻接表

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

const int maxv = 110;
const int INF = 1000000000;

struct node{

	int v;
	int d;

	node(int u, int dis):v(u), d(dis){ }
	node(){ }
};

int n, m, d[maxv];
bool vis[maxv];
vector<node> Adj[maxv];

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

		for (int j = 0; j < Adj[u].size(); j++)
		{
			int v = Adj[u][j].v;
			if ( vis[v] == false && Adj[u][j].d < d[v] )
			{
				d[v] = Adj[u][j].d;
			}
		}
	}
	return ans;
}

int main(){

	while ( scanf("%d %d", &m, &n) != EOF && m )
	{
		for (int i = 1; i <= n; i++)
		{
			Adj[i].clear();
		}

		memset(vis, false, sizeof(vis));
		fill(d, d + maxv, INF);

		int u, v, dis;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &u, &v, &dis);

			Adj[u].push_back(node(v, dis));
			Adj[v].push_back(node(u, dis));
		}

		int ans = Prim();

		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("?\n");
	}

	system("pause");
	return 0;
}
