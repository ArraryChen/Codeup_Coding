#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 210;

int num[maxn];

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		int search_num, pos = -1;
		scanf("%d", &search_num);
		for (int i = 0; i < n; i++)
		{
			if ( search_num == num[i] )
			{
				pos = i;
				break;
			}
		}
		printf("%d\n", pos);
	}

	system("pause");
	return 0;
}
