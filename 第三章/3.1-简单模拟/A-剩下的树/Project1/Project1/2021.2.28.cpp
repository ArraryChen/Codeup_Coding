#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10010;

bool tree[maxn];

int main(){

	//n:马路长度
	//m:移走区间的个数
	int n, m;
	while ( scanf("%d %d", &n, &m), n || m )
	{
		fill(tree, tree + maxn, true);

		int x, y;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);

			for (int j = x; j <= y; j++)
			{
				tree[j] = false;
			}
		}

		int count = 0;
		for (int k = 0; k <= n; k++)
		{
			if ( tree[k] == true ) count++;
		}
		printf("%d\n", count);
	}

	system("pause");
	return 0;
}
