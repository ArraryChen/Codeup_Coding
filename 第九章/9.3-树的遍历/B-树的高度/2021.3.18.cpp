#include<cstdio>
#include<iostream>

using namespace std;

struct node{

	int layer;

}tree[1000010];

int max_deep = 1;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		max_deep = 1;

		tree[1].layer = 1;

		int parent, child;
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &parent, &child);

			tree[child].layer = tree[parent].layer + 1;

			if (tree[child].layer > max_deep) max_deep = tree[child].layer;
		}

		printf("%d\n", max_deep);
	}

	system("pause");
	return 0;
}
