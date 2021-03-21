#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 110;
const int INF = 1000000000;

//n:结点数
//m:道路数
//G:图
//d:保存结点0到其它结点的最短路径长度
//father:保存每个结点的父节点(本题需要用到并查集)
int n, m;
int G[maxv][maxv], d[maxv], father[maxv];

//vis:判断某结点是否被遍历过
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

		if ( u == -1 ) return;
		vis[u] = true;

		for (int v = 0; v < n; v++)
		{
			if ( vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v] )
			{
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

int findFather(int x){

	while ( x != father[x] )
		x = father[x];

	return x;
}

int main(){

	while ( scanf("%d %d", &n, &m) != EOF )
	{
		//初始化
		memset(vis, false, sizeof(vis));
		fill(G[0], G[0] + maxv * maxv, INF);
		fill(d, d + maxv, INF);

		for (int i = 0; i < n; i++)
		{
			father[i] = i;
		}

		//a,b:临时变量, 保存结点编号
		//w:边权
		int a, b, w = 1;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			int faA = findFather(a);
			int faB = findFather(b);

			//易错点二:当题目再输入边的时候,某这两个结点之前已经出现过,就不能再读入其数据了,(后面出现的边权大)

			//case : 0 1
			//       . .
			//       . .
			//       0 1 (这里就不能再读入了)
			if ( faA != faB )
			{
				father[faA] = faB;
				G[a][b] = G[b][a] = w;
			}

			//易错点一:由于题目给的边的上限是500,故2^500超出了int范围,需要取余
			w = (w * 2) % 100000;
		}

		Dijstra(0);

		for (int i = 1; i < n; i++)
		{
			if ( d[i] == INF )
				printf("-1\n");
			else
				printf("%d\n", d[i] % 100000);
		}
	}

	system("pause");
	return 0;
}
