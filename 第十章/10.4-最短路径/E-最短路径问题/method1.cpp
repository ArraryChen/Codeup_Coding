//������: �����߶�------��һ�߶�:���·������;�ڶ��߶�:��������
//����һ: DFS + Dijkstra

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

const int maxv = 1010;
const int INF = 1000000000;

//n:�����
//m:����
//s:���
//t:�յ�
//minCost:��С����
int n, m, s, t, minCost;

//G:ͼ
//cost:�������֮�仨��
//d:��㵽�յ�����·������
int G[maxv][maxv], cost[maxv][maxv], d[maxv];
bool vis[maxv];

//pre:���·���Ͻ���ǰ��
vector<int> pre[maxv];

//path:���·��
//tempPath:��ʱ·��
vector<int> path, tempPath;

//Dijstra:�ҵ����·���Ͻ���ǰ�� && ���·������
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

//DFS:�ҵ�������������·��(������С)
void DFS(int v){

	//�����������
	if ( v == s )
	{
		tempPath.push_back(v);
		
		//tempCost:��ǰ���·���Ļ���
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

		//�ý���������
		tempPath.pop_back();
		return;
	}

	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}

	//�ý���������
	tempPath.pop_back();
}

int main(){

	//ѭ������
	while ( scanf("%d %d", &n, &m) != EOF && n && m )
	{
		//��ʼ��
		memset(vis, false, sizeof(vis));
		fill(d, d + maxv, INF);
		fill(G[0], G[0] + maxv * maxv, INF);
		fill(cost[0], cost[0] + maxv * maxv, INF);

		minCost = INF;

		//ѭ�������Ȩ,����
		for (int i = 0; i < m; i++)
		{
			int u, v, d, p;
			scanf("%d %d %d %d", &u, &v, &d, &p);

			G[u][v] = G[v][u] = d;
			cost[u][v] = cost[v][u] = p;
		}

		//�������,�յ�
		scanf("%d %d", &s, &t);

		//Dijstra:�ҵ����·���Ͻ���ǰ�� && ���·������
		Dijkstra(s);

		//DFS:�ҵ�������������·��(������С)
		DFS(t);

		//������·������,��С����
		printf("%d %d\n", d[t], minCost);

	}

	system("pause");
	return 0;
}
