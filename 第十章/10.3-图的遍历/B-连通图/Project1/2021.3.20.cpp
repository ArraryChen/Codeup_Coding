#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

const int MAXV = 1010;

vector<int> Adj[MAXV];

int n, m, Count;
bool vis[MAXV];

void DFS(int u){

	vis[u] = true;

	for (int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i];
		if ( vis[v] == false )
		{
			DFS(v);
		}
	}
}

void DFSTrave(){

	Count = 0;
	for (int i = 1; i <= n; i++)
	{
		if ( vis[i] == false )
		{
			Count++;
			DFS(i);
		}
	}
}

int main(){

	while ( scanf("%d %d", &n, &m) != EOF && n )
	{
		memset(vis, false, sizeof(vis));

		int u, v;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);
			Adj[u].push_back(v);
			Adj[v].push_back(u);
		}

		DFSTrave();

		if (Count == 1)
			printf("YES\n");
		else
			printf("NO\n");

		for (int i = 1; i <= n; i++)
		{
			Adj[i].clear();
		}
	}

	system("pause");
	return 0;
}
