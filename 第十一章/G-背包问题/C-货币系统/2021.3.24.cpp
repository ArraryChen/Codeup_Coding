#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxv = 30;
const int maxn = 10010;

//d[i]:��֪���ҿ��Թ����Ǯ��Ϊi�ķ�����
//v[i]:��Ÿ��ֱ�ֵ
long long d[maxn], v[maxv];

int main(){

	//V:���ҵ�������Ŀ
	//N:���������Ǯ
	int V, N;
	while ( scanf("%d %d", &V, &N) != EOF )
	{
		//��ʼ������d
		memset(d, 0, sizeof(d));

		//ѭ��������ֱ�ֵ
		for (int i = 0; i < V; i++)
		{
			scanf("%lld", &v[i]);
		}

		//Ĭ�Ͻ������Ǯ��Ϊ0ʱ,������Ϊ1
		d[0] = 1;

		for (int i = 0; i < V; i++)
		{
			for (int j = v[i]; j <= N; j++)
			{
				//����Ǯ��Ϊjʱ�ķ����� = ��ѡ���ֵv[i]�ķ����� + ѡ���ֵv[i]�ķ�����
				d[j] = d[j] + d[j- v[i]];
			}
		}
		printf("%lld\n", d[N]);
	}

	system("pause");
	return 0;
}
