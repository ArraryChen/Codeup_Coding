#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 110;
const int INF = 1000000000;

//n:�����
//m:��·��
//G:ͼ
//d:������0�������������·������
//father:����ÿ�����ĸ��ڵ�(������Ҫ�õ����鼯)
int n, m;
int G[maxv][maxv], d[maxv], father[maxv];

//vis:�ж�ĳ����Ƿ񱻱�����
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
		//��ʼ��
		memset(vis, false, sizeof(vis));
		fill(G[0], G[0] + maxv * maxv, INF);
		fill(d, d + maxv, INF);

		for (int i = 0; i < n; i++)
		{
			father[i] = i;
		}

		//a,b:��ʱ����, ��������
		//w:��Ȩ
		int a, b, w = 1;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			int faA = findFather(a);
			int faB = findFather(b);

			//�״���:����Ŀ������ߵ�ʱ��,ĳ���������֮ǰ�Ѿ����ֹ�,�Ͳ����ٶ�����������,(������ֵı�Ȩ��)

			//case : 0 1
			//       . .
			//       . .
			//       0 1 (����Ͳ����ٶ�����)
			if ( faA != faB )
			{
				father[faA] = faB;
				G[a][b] = G[b][a] = w;
			}

			//�״��һ:������Ŀ���ıߵ�������500,��2^500������int��Χ,��Ҫȡ��
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
