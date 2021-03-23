#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxv = 110;
const int maxm = 5000;
const int INF = 1000000000;

struct node{

	int u, v;
	int cost, flag;

}E[maxm];

int n, m, father[maxv];

//重点:
//在采用Kruskal算法时, 应当优先选取flag = 1(已建好的路)进行选择
//统计完以及建好的路后, 在根据花销升序选择修建的路
bool cmp(node a, node b){

	if ( a.flag != b.flag )
		return a.flag > b.flag;
	else
		return a.cost < b.cost;
}

int findFather(int x){

	int a = x;
	while ( x != father[x] )
	{
		x = father[x];
	}

	while ( a != father[a] )
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int Kruskal(){

	int ans = 0, Num_edge = 0;
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}

	sort(E, E + m, cmp);

	for (int i = 0; i < m; i++)
	{
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		if (faU != faV)
		{
			father[faU] = faV;
			if (E[i].flag != 1)
				ans += E[i].cost;
			Num_edge++;
			if (Num_edge == n-1) break;
		}
	}
	if(Num_edge != n-1) return -1;
	else return ans;
}

int main(){

	while ( scanf("%d", &n) != EOF && n )
	{
		m = n*(n-1)/2;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d %d", &E[i].u, &E[i].v, &E[i].cost, &E[i].flag);
		}

		printf("%d\n", Kruskal());
	}

	system("pause");
	return 0;
}
