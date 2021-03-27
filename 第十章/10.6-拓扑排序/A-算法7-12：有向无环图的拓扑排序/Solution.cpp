#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

const int maxv = 55;

int n, G[maxv][maxv], inDegree[maxv];

vector<int> ans;

bool topologicalSort(){

	int num = 0;
	stack<int> q;
	for (int i = 0; i < n; i++)
	{
		if ( inDegree[i] == 0 )
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int u = q.top();
		ans.push_back(u);
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if ( G[u][i] != 0 )
			{
				inDegree[i]--;
				if (inDegree[i] == 0)
					q.push(i);
			}
		}
		num++;
	}
	if(num == n) return true;
	else return false;
}

int main(){

	while ( scanf("%d", &n) != EOF && n )
	{
		memset(inDegree, 0, sizeof(inDegree));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &G[i][j]);
				if (G[i][j] != 0)
					inDegree[j]++;
			}
		}
		
		if (topologicalSort() == false)
			printf("ERROR\n");
		else
			for (int i = 0; i < ans.size(); i++)
			{
				printf("%d", ans[i]);
				if (i < ans.size() -1)
					printf(" ");
				else
					printf("\n");
			}
		ans.clear();
	}

	system("pause");
	return 0;
}
