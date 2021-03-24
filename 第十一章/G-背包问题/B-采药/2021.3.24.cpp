#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 110;
const int maxt = 1010;

//d[i]:当时间为i时,能获得的最大价值
//w[i]:采草药i需要花费的时间
//c[i]:采草药i获得的收益
int d[maxt], w[maxn], c[maxn];

int main(){

	int T, M;
	while ( scanf("%d %d", &T, &M) != EOF )
	{
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d", &w[i], &c[i]);
		}

		for (int i = 0; i <= T; i++)
		{
			d[i] = 0;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = T; j >= w[i]; j--)
			{
				d[j] = max(d[j], d[j - w[i]] + c[i]);
			}
		}
		int ans = -1;
		for (int i = 0; i <= T; i++)
		{
			if ( d[i] > ans )
			{
				ans = d[i];
			}
		}
		printf("%d\n", ans);
	}

	system("pause");
	return 0;
}
