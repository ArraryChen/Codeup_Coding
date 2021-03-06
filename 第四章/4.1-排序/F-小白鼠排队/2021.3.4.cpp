#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

struct mouse{

	int weight;
	char color[20];

}mouses[110];

bool cmp(mouse a, mouse b){

	return a.weight > b.weight;

}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d %s", &mouses[i].weight, mouses[i].color);
		}

		sort(mouses, mouses + n, cmp);

		for (int i = 0; i < n; i++)
		{
			printf("%s\n", mouses[i].color);
		}
	}

	system("pause");
	return 0;
}
