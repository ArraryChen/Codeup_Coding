//ÓÐ´íÎó

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//
//const int maxv = 110;
//const int INF = 1000000000;
//
//int n, m;
//int G[maxv][maxv], d[maxv];
//bool vis[maxv];
//
//void Dijstra(int s){
//
//	d[s] = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int u = -1, MIN = INF;
//		for (int j = 0; j < n; j++)
//		{
//			if ( vis[j] == false && d[j] < MIN )
//			{
//				u = j;
//				MIN = d[j];
//			}
//		}
//
//		if ( u == -1 ) return;
//		vis[u] = true;
//
//		for (int v = 0; v < n; v++)
//		{
//			if ( vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v] )
//			{
//				d[v] = d[u] + G[u][v];
//			}
//		}
//	}
//}
//
//int main(){
//	
//	while ( scanf("%d %d", &n, &m) != EOF )
//	{
//		memset(vis, false, sizeof(vis));
//		fill(G[0], G[0] + maxv, INF);
//		fill(d, d + maxv, INF);
//
//		int w = 1, u, v;
//		for (int i = 0; i < m; i++)
//		{
//			scanf("%d %d", &u, &v);
//			G[u][v] = w;
//
//			w *= 2;
//		}
//
//		Dijstra(0);
//
//		for (int i = 1; i < n; i++)
//		{
//			if ( d[i] == INF )
//				printf("-1\n");
//			else
//				printf("%d\n", d[i] % 100000);
//		}
//	}
//
//	system("pause");
//	return 0;
//}
