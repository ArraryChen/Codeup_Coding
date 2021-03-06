#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool cmp(int a, int b){

	return a > b;

}

int main(){

	int L, N;
	while ( scanf("%d %d", &L, &N) != EOF )
	{
		int block;
		vector<int> blocks;

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &block);
			blocks.push_back(block);
		}

		sort(blocks.begin(), blocks.end(), cmp);

		int total = 0, count = 0;
		for (int i = 0; i < blocks.size(); i++)
		{
			total += blocks[i];
			count++;

			if ( total >= L ) break;
		}

		if ( total >= L ) printf("%d\n", count);
		else printf("impossible\n");
	}
	system("pause");
	return 0;
}
