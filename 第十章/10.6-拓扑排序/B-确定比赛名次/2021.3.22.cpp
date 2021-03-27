#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

const int maxv = 550;

int n, m, inDegree[maxv];

vector<int> ans;
vector<int> Adj[maxv];

void topo(){

	set<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.insert(i);
		}
	}

	while ( !q.empty() )
	{
		int u = *(q.begin());
		ans.push_back(u);
		q.erase(q.begin());

		for (int i = 0; i < Adj[u].size(); i++)
		{
			int v = Adj[u][i];
			inDegree[v]--;
			if ( inDegree[v] == 0 )
			{
				q.insert(v);
			}
		}
		Adj[u].clear();

	}
}

int main(){

	while ( scanf("%d %d", &n, &m) != EOF && n )
	{
		memset(inDegree, 0, sizeof(inDegree));

		int u, v;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);

			Adj[u].push_back(v);

			inDegree[v]++;
		}

		topo();

		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d", ans[i]);
			if (i < ans.size() - 1)
				printf(" ");
			else
				printf("\n");
		}

		ans.clear();
	}

	system("pause");
	return 0;
}
