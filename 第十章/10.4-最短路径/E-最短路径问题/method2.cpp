//方法一:Dijkstra

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 1010;
const int INF = 1000000000;

int n, m, s, t;
int G[maxv][maxv], d[maxv], cost[maxv][maxv], c[maxv];
bool vis[maxv];

//int pre[maxv]; //(非题目要求)pre数组可以保存最短路径上结点的前驱

void Dijkstra(int s){

	d[s] = c[s] = 0;

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
					c[v] = c[u] + cost[u][v];
					//pre[v] = u; //(非题目要求)保存最短路径上结点前驱
				}
				else if ( d[u] + G[u][v] == d[v] )
				{
					if ( c[u] + cost[u][v] < c[v] )
					{
						c[v] = c[u] + cost[u][v];
						//pre[v] = u; //(非题目要求)保存最短路径上结点前驱
					}
				}
			}
		}
	}
}

//(非题目要求)通过DFS,可以打印最短路径
//void DFS(int v){
//	if (v == s)
//	{
//		printf("%d", v);
//		return;
//	}
//	DFS(pre[v]);
//	printf(" %d", v);
//}

int main(){

	while ( scanf("%d %d", &n, &m) != EOF && n && m )
	{
		memset(vis, false, sizeof(vis));
		fill(c, c + maxv, INF);
		fill(d, d + maxv, INF);
		fill(G[0], G[0] + maxv*maxv, INF);
		fill(cost[0], cost[0] + maxv*maxv, INF);

		//(非题目要求)初始化pre数组
		/*for (int i = 1; i <= n; i++)
		{
			pre[i] = i;
		}*/

		int a, b, dis, p;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d %d", &a, &b, &dis, &p);

			G[a][b] = G[b][a] = dis;
			cost[a][b] = cost[b][a] = p;
		}

		scanf("%d %d", &s, &t);

		Dijkstra(s);

		//(非题目要求)打印最短路径
		/*DFS(t);
		printf("\n");*/

		printf("%d %d\n", d[t], c[t]);
	}

	system("pause");
	return 0;
}

