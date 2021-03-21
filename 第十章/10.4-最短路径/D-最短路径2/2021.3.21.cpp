//���ⲻ�����ڽӾ���,������ظ��ߵ�����

#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 1010;
const int INF = 1000000000;

struct node{

	//v:�����
	//w:���Ȩֵ
	int v, w;
	node(int x, int y): v(x), w(y){}

};

//n:�����
//m:����
//s:���
//t:�յ�
int n, m, s, t;

//d:���·������
//pre:���·���ϵĽ��ǰ��
int d[maxv], pre[maxv];
bool vis[maxv];

//Adj:�ڽӱ�
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

//����pre��ŵ������·���ϵ�ǰ��,��Ҫ�������
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
		//��ʼ�� vis,d ����
		memset(vis, false, sizeof(vis));
		fill(d, d + maxv, INF);

		//��ʼ��pre����
		for (int i = 1; i <= n; i++)
		{
			pre[i] = i;
		}
		
		//��ʼ���ڽӱ�
		for (int i = 1; i <= n; i++)
		{
			Adj[i].clear();
		}

		//�����
		int u, v, w;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			
			Adj[u].push_back(node(v, w));
			Adj[v].push_back(node(u, w));
		}

		//�ҵ����·��
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
