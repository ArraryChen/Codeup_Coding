//DFS + 邻接表(这题不能用邻接矩阵,因为结点个数不确定(可能会很多))

#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

const int MAXV = 1000010;

vector<int> Adj[MAXV];

int n, Count;
bool vis[MAXV] = {false};

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
	for (int u = 0; u <= n; u++)
	{
		if (vis[u] == false)
		{
			Count++;
			DFS(u);
		}
	}
}

int main(){

	memset(vis, true, sizeof(vis));

	int u, v, x;

	n = -1;
	while ( scanf("%d %d", &u, &v ) != EOF )
	{
		Adj[u].push_back(v);
		Adj[v].push_back(u);

		vis[u] = vis[v] = false;

		x = (u > v) ? u : v;
		n = (x > n) ? x : n;
	}

	DFSTrave();

	printf("%d\n", Count);

	system("pause");
	return 0;
}
