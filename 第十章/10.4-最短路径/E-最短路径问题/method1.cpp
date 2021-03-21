//典型题: 两个尺度------第一尺度:最短路径长度;第二尺度:花费最少
//方法一: DFS + Dijkstra

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

const int maxv = 1010;
const int INF = 1000000000;

//n:结点数
//m:边数
//s:起点
//t:终点
//minCost:最小花销
int n, m, s, t, minCost;

//G:图
//cost:两个结点之间花销
//d:起点到终点的最短路径长度
int G[maxv][maxv], cost[maxv][maxv], d[maxv];
bool vis[maxv];

//pre:最短路径上结点的前驱
vector<int> pre[maxv];

//path:最短路径
//tempPath:临时路径
vector<int> path, tempPath;

//Dijstra:找到最短路径上结点的前驱 && 最短路径长度
void Dijkstra(int s){

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

		for (int v = 1; v <= n; v++)
		{
			if ( vis[v] == false && G[u][v] != INF )
			{
				if ( d[u] + G[u][v] < d[v] )
				{
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if ( d[u] + G[u][v] == d[v] )
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}

//DFS:找到符合题意的最短路径(花销最小)
void DFS(int v){

	//遍历到了起点
	if ( v == s )
	{
		tempPath.push_back(v);
		
		//tempCost:当前最短路径的花销
		int tempCost = 0;
		
		for (int i = tempPath.size() - 1; i > 0; i--)
		{
			int id = tempPath[i], idNext = tempPath[i-1];
			tempCost += cost[id][idNext];
		}

		if ( tempCost < minCost )
		{
			minCost = tempCost;
			path = tempPath;
		}

		//该结点遍历结束
		tempPath.pop_back();
		return;
	}

	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}

	//该结点遍历结束
	tempPath.pop_back();
}

int main(){

	//循环输入
	while ( scanf("%d %d", &n, &m) != EOF && n && m )
	{
		//初始化
		memset(vis, false, sizeof(vis));
		fill(d, d + maxv, INF);
		fill(G[0], G[0] + maxv * maxv, INF);
		fill(cost[0], cost[0] + maxv * maxv, INF);

		minCost = INF;

		//循环输入边权,花销
		for (int i = 0; i < m; i++)
		{
			int u, v, d, p;
			scanf("%d %d %d %d", &u, &v, &d, &p);

			G[u][v] = G[v][u] = d;
			cost[u][v] = cost[v][u] = p;
		}

		//输入起点,终点
		scanf("%d %d", &s, &t);

		//Dijstra:找到最短路径上结点的前驱 && 最短路径长度
		Dijkstra(s);

		//DFS:找到符合题意的最短路径(花销最小)
		DFS(t);

		//输出最短路径长度,最小花销
		printf("%d %d\n", d[t], minCost);

	}

	system("pause");
	return 0;
}
