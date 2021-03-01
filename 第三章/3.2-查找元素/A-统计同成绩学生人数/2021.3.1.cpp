#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 1010;

int score[maxn] = { 0 };

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &score[i]);
		}

		int search_score, count = 0;
		scanf("%d", &search_score);

		for (int i = 0; i < n; i++)
		{
			if ( score[i] == search_score ) count++;
		}
		printf("%d\n", count);
	}

	system("pause");
	return 0;
}
