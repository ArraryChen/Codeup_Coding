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

	int fa = findFather(a);
	int fb = findFather(b);

	if ( fa != fb )
	{
		father[fa] = fb;
	}
}

int main(){

	int m, n;
	while ( scanf("%d %d", &n, &m) != EOF && n )
	{
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

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (father[i] == i) cnt++;
		}

		if (cnt == 1 && m == n - 1) 
			printf("Yes\n");
		else 
			printf("No\n");
	}

	system("pause");
	return 0;
}
