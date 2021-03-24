#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 20010;

int d[maxn], v[maxn];

int main(){

	int n, V;
	while ( scanf("%d %d", &V, &n) != EOF )
	{
		//��ʼ��ÿ�ֱ���������
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &v[i]);
		}

		//��ʼ��ʣ��ռ�
		for (int i = 0; i <= V; i++)
		{
			d[i] = V;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = V; j >= v[i]; j--)
			{
				d[j] = min(d[j], d[j - v[i]] - v[i]);
			}
		}
		int min = V;
		for (int i = 0; i <= V; i++)
		{
			if ( min > d[i] )
			{
				min = d[i];
			}
		}

		printf("%d\n", min);
	}

	system("pause");
	return 0;
}
