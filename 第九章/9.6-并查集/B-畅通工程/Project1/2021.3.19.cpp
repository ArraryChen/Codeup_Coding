#include<cstdio>
#include<iostream>

using namespace std;

int father[1010];

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

void Union(int a, int b){

	int faA = findFather(a);
	int faB = findFather(b);

	if ( faA != faB )
	{
		father[faA] = faB;
	}
}

int main(){

	int n, m;
	while ( scanf("%d", &n) != EOF && n )
	{
		scanf("%d", &m);

		for (int i = 1; i <= n; i++)
		{
			father[i] = i;
		}

		int n1, n2;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &n1, &n2);
			Union(n1, n2);
		}
		getchar();

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if ( father[i] == i )
			{
				cnt++;
			}
		}

		printf("%d\n", cnt - 1);
	}

	system("pause");
	return 0;
}
