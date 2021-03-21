//此题不能用邻接矩阵,会出现重复边的问题

#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 1010;
const int INF = 1000000000;

struct node{

	//v:结点编号
	//w:结点权值
	int v, w;
	node(int x, int y): v(x), w(y){}

};

//n:结点数
//m:边数
//s:起点
//t:终点
int n, m, s, t;

//d:最短路径长度
//pre:最短路径上的结点前驱
int d[maxv], pre[maxv];
bool vis[maxv];

//Adj:邻接表
vector<node> Adj[maxv];

void Dijstra(int s){

	d[s] = 0;
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

		if (u == -1) return;
		vis[u] = true;
	
		for (int j = 0; j < Adj[u].size(); j++)
		{
			int v = Adj[u][j].v;

			if ( vis[v] == false )
			{
				if ( d[u] + Adj[u][j].w < d[v] )
				{
					d[v] = d[u] + Adj[u][j].w;
					pre[v] = u;
				}
				else if ( d[u] + Adj[u][j].w == d[v] && u < pre[v] )
				{
					pre[v] = u;
				}
			}
		}
	}
}

//由于pre存放的是最短路径上的前驱,需要逆序输出
void DFS(int v){

	if ( v == s )
	{
		printf("%d", v);
		return;
	}

	DFS(pre[v]);
	printf(" %d", v);
}

int main(){

	while ( scanf("%d %d %d %d", &n, &m, &s, &t) != EOF )
	{
		//初始化 vis,d 数组
		memset(vis, false, sizeof(vis));
		fill(d, d + maxv, INF);

		//初始化pre数组
		for (int i = 1; i <= n; i++)
		{
			pre[i] = i;
		}
		
		//初始化邻接表
		for (int i = 1; i <= n; i++)
		{
			Adj[i].clear();
		}

		//输入边
		int u, v, w;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			
			Adj[u].push_back(node(v, w));
			Adj[v].push_back(node(u, w));
		}

		//找到最短路径
		Dijstra(s);

		if (d[t] == INF)
			printf("can't arrive\n");
		else
		{
			printf("%d\n",d[t]);
			DFS(t);
			printf("\n");
		}
	}

	system("pause");
	return 0;
}
