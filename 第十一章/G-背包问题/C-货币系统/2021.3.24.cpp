#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxv = 30;
const int maxn = 10010;

//d[i]:已知货币可以构造出钱数为i的方案数
//v[i]:存放各种币值
long long d[maxn], v[maxv];

int main(){

	//V:货币的种类数目
	//N:构造的数量钱
	int V, N;
	while ( scanf("%d %d", &V, &N) != EOF )
	{
		//初始化数组d
		memset(d, 0, sizeof(d));

		//循环输入各种币值
		for (int i = 0; i < V; i++)
		{
			scanf("%lld", &v[i]);
		}

		//默认将构造的钱数为0时,方案数为1
		d[0] = 1;

		for (int i = 0; i < V; i++)
		{
			for (int j = v[i]; j <= N; j++)
			{
				//构造钱数为j时的方案数 = 不选择币值v[i]的方案数 + 选择币值v[i]的方案数
				d[j] = d[j] + d[j- v[i]];
			}
		}
		printf("%lld\n", d[N]);
	}

	system("pause");
	return 0;
}
